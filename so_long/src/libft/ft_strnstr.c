/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:28:45 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/08 15:24:04 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i])
	{
		if (haystack[i] == needle[0] && i <= len - ft_strlen(needle))
		{
			if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
