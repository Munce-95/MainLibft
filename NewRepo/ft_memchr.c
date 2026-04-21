/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 14:59:11 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-12 14:59:11 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Hello\0World";
	char	*res;

	res = ft_memchr(str, 'o', 11);
	if (res)
		printf("Trouvé: %c\n", *res);
	else
		printf("Pas trouvé\n");

	res = ft_memchr(str, 'z', 11);
	if (res)
		printf("Trouvé: %c\n", *res);
	else
		printf("Pas trouvé\n");

	res = ft_memchr(str, '\0', 11);
	if (res)
		printf("Trouvé NULL byte\n");
	else
		printf("Pas trouvé\n");

	return (0);
}*/
