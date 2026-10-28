def seed_packet_sort(labels: list[str]) -> list[str]:
    lab = list(labels)
    n = len(lab)
    def count_vowels(s: str) -> int:
        vowels = "aeiouyAEIOUY"
        count = 0
        for char in s:
            if char in vowels:
                count += 1
        return count
    swapped = True
    while swapped:
        swapped = False
        for i in range(n - 1):
            s1 = lab[i]
            s2 = lab[i + 1]
            c1 = len(s1) > len(s2)
            c2 = (len(s1) == len(s2)) and (s1.lower() > s2.lower())
            c3 = (len(s1) == len(s2)) and (s1.lower() == s2.lower()) and (count_vowels(s1) > count_vowels(s2))
            if c1 or c2 or c3:
                temp = lab[i]
                lab[i] = lab[i + 1]
                lab[i + 1] = temp
                swapped = True
    return lab

print(seed_packet_sort(["apple", "cat", "banana", "dog", "elephant"]))
print(seed_packet_sort(["aaa", "bbb", "AAA", "BBB"]))
print(seed_packet_sort(["Bb", "bb", "BB"]))
print(seed_packet_sort(["hello", "world", "hi", "test"]))
print(seed_packet_sort([]))
print(seed_packet_sort([""]))
