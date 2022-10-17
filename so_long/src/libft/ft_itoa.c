/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:51:55 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/08 16:55:54 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(long n)
{
	int	len_n;
	int	i;

	i = 0;
	if (n == 0)
		return (2);
	if (n < 0)
		len_n = 1;
	else
		len_n = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	len_n = len_n + i;
	return (len_n + 1);
}

static char	*ft_myitoa(long n, char *str, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	if (n == 0)
	{
		str[0] = '0';
	}
	str[len - 1] = '\0';
	if (n > 0)
	{
		while (n != 0)
		{
			str[len - 2] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
		if (i == 1)
			str[0] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	x;

	x = (long)n;
	len = ft_len_n(x);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_myitoa(x, str, len);
	return (str);
}
