/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-13 09:38:01 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-13 09:38:01 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}
/*
int	main(void)
{
	char	*test1 = "   123451545313512413526841";
	char	*test2 = "   123451545313512413526841";
	char 	*test3 = "+987";
	char	*test4 = "   \t \r \v \n -56abc";
	char	*test5 = "--12";

	printf("Test 1 : %d\n", ft_atoi(test1));
	printf("Test 2 : %d\n", atoi(test2));
	printf("Test 3 : %d\n", ft_atoi(test3));
	printf("Test 4 : %d\n", ft_atoi(test4));
	printf("Test 5 : %d\n", ft_atoi(test5));

	return (0);
}*/
