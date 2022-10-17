/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:48:19 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/08 15:22:30 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!src && !dst)
		return (0);
	if ((const char *)src > (char *)dst)
	{
		while (n > i)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else if ((const char *)src < (char *)dst)
	{
		while (n > 0)
		{
			((char *)dst)[n - 1] = ((const char *)src)[n - 1];
			n--;
		}
	}
	return ((char *)dst);
}
