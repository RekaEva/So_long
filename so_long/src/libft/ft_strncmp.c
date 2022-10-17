/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:18:04 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/10 13:48:25 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((s11[i] != s22[i] && s11[i] > s22[i]))
			return (s11[i] - s22[i]);
		if (s11[i] != s22[i] && s11[i] < s22[i])
			return (s11[i] - s22[i]);
		if (!s11[i] || !s22[i])
			return (0);
		i++;
	}
	return (0);
}
