/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-09 13:36:03 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-09 13:36:03 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*
int	main(void)
{
	char	data1[] = "abcdefg";
	char	data2[] = "abcdefg";
	char	*src1 = data1 + 2;
	char	*dst1 = data1;
	char	*src2 = data2 + 2;
	char	*dst2 = data2;

	ft_memmove(dst1, src1, 4);
	memmove(dst2, src2, 4);
	printf("Test 1 (Overlap gauche) : %s\n", data1);
	printf("Vrai 1 (Overlap gauche) : %s\n", data2);

	char	data3[] = "abcdefg";
	char	data4[] = "abcdefg";
	char	*src3 = data3;
	char	*dst3 = data3 + 2;
	char	*src4 = data4;
	char	*dst4 = data4 + 2;

	ft_memmove(dst3, src3, 4);
	memmove(dst4, src4, 4);
	printf("Test 2 (Overlap droite) : %s\n", data3);
	printf("Vrai 2 (Overlap droite) : %s\n", data4);

	return (0);
}*/