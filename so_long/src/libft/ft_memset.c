/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:08:01 by cpollito          #+#    #+#             */
/*   Updated: 2021/10/22 16:26:07 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	size_t			i;

	b2 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b2[i] = c;
		i++;
	}
	return (b2);
}
