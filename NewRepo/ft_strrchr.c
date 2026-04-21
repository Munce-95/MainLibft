/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 14:17:47 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-12 14:17:47 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}
/*
int	main(void)
{
	char	str[] = "Hello World";

	printf("%s\n\n", str);

	printf("Test 1 ('l'):\n");
	printf("%s\n\n", ft_strrchr(str, 'l'));

	printf("Test 2 ('z'):\n");
	if (ft_strrchr(str, 'z') == NULL)
		printf("NULL\n");
	return (0);
}*/
