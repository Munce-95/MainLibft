import os
import json
from supabase import create_client, Client

class DatabaseManager:
    def __init__(self):
        # Récupération des informations de connexion
        url = os.getenv("SUPABASE_URL")
        key = os.getenv("SUPABASE_KEY")
        self.supabase: Client = create_client(url, key)
        
        # Nettoyage de l'ID Twitch pour les noms de colonnes/tables
        self.twitch_id = os.getenv("TWITCH_CHANNEL").lower().replace("-", "_")
        self.music_table = os.getenv("MUSIC_TABLE", "music_cache")
        self.listened_column = f"listened_{self.twitch_id}"
        self.viewer_table = f"viewers_{self.twitch_id}"

    def initialize_infrastructure(self):
        """
        Vérifie et crée la structure de la base de données.
        Appelle les fonctions RPC définies sur Supabase.
        """
        print(f"[DB] Initialisation de l'infrastructure pour {self.twitch_id}...")
        try:
            # 1. Ajoute la colonne listened_XXX dans la table music_cache (si elle n'existe pas)
            # La table music_cache elle-même doit être créée une fois via l'éditeur SQL de Supabase
            self.supabase.rpc('add_column_if_not_exists', {
                't_name': self.music_table,
                'c_name': self.listened_column,
                'c_type': 'int4 DEFAULT 0'
            }).execute()

            # 2. Crée la table des viewers spécifique au streamer
            self.supabase.rpc('create_viewer_table', {
                'table_name': self.viewer_table
            }).execute()

            print("[DB] Infrastructure validée avec succès.")
            return True
        except Exception as e:
            print(f"[DB] Erreur d'initialisation : {e}")
            return False

    def migrate_legacy_data(self):
        """
        Transfère les données de music_cache.json vers Supabase.
        Ne s'exécute que si le fichier existe.
        """
        json_file = 'music_cache.json'
        
        if not os.path.exists(json_file):
            return # Le fichier n'existe plus, migration déjà faite

        print(f"[Migration] Fichier {json_file} détecté. Début du transfert...")

        try:
            with open(json_file, 'r', encoding='utf-8') as f:
                data = json.load(f)

            if not data:
                print("[Migration] Fichier vide.")
                return

            entries = []
            for uri, info in data.items():
                entries.append({
                    "uri": uri,
                    "title": info.get("title", "Unknown"),
                    "artist": info.get("artist", "Unknown"),
                    "yt_id": info.get("yt_id"),
                    "duration": info.get("duration", 0),
                    "is_blacklisted": info.get("is_blacklisted", False),
                    "is_archived": info.get("is_archived", False),
                    self.listened_column: info.get("listened", 0)
                })

            # Insertion par paquets de 100 (pour éviter les timeouts)
            batch_size = 100
            for i in range(0, len(entries), batch_size):
                batch = entries[i:i+batch_size]
                # .upsert avec on_conflict='uri' évite les doublons si on relance le script
                self.supabase.table(self.music_table).upsert(batch, on_conflict="uri").execute()
                print(f"[Migration] {i + len(batch)} / {len(entries)} titres transférés...")

            # Une fois fini, on renomme pour éviter de recommencer au prochain reboot
            os.rename(json_file, f"{json_file}.bak")
            print(f"[Migration] Succès ! {json_file} a été renommé en .bak")

        except Exception as e:
            print(f"[Migration] Erreur critique : {e}")

# Exemple d'utilisation dans ton main.py :
# db = DatabaseManager()
# if db.initialize_infrastructure():
#     db.migrate_legacy_data()