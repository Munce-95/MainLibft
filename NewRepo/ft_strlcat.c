/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 13:05:34 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-12 13:05:34 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	s_len = 0;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] && (d_len + i) < (size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[100] = "Ohayo Sekai, ";
	char	src[] = "Good Morning World !";
	unsigned int	result;

	result = ft_strlcat(dest, src, sizeof(dest));

	printf("Résultat de strlcat : %u\n", result);
	printf("Résultat final : \"%s\"\n", dest);

	return (0);
}*/