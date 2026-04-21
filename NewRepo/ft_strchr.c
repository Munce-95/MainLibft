/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 13:33:01 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-12 13:33:01 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Hello World";

	printf("%s\n\n", str);

	printf("Test 1 ('o'):\n");
	printf("%s\n\n", ft_strchr(str, 'o'));

	printf("Test 2 ('z'):\n");
	if (ft_strchr(str, 'z') == NULL)
		printf("NULL\n");

	return (0);
}*/
