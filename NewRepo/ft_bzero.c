/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-10 09:51:03 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-10 09:51:03 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*

int main(void)
{
	char str[10] = "abcdefghi";
	int i;

	ft_bzero(str, 5);
	i = 0;
	while (str[i] == '\0')
	{
		printf("%d ", str[i]);
		i++;
	}
	while (str[i] != '\0')
	{
		printf("%d ", str[i]);
		i++;
	}
	printf("\n");

	return 0;
}*/