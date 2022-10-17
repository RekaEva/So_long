/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:03:44 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/08 15:22:17 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i <= (n - 1))
	{
		if ((s11[i] != s22[i] && s11[i] > s22[i]))
			return (s11[i] - s22[i]);
		if (s11[i] != s22[i] && s11[i] < s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}
