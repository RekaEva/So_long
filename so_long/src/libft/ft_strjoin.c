/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:49:39 by cpollito          #+#    #+#             */
/*   Updated: 2021/11/08 16:46:19 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*s12;
	char	*cs1;
	char	*cs2;
	int		i;

	i = 0;
	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s12)
		return (NULL);
	while (*cs1)
		s12[i++] = *cs1++;
	while (*cs2)
		s12[i++] = *cs2++;
	s12[i] = '\0';
	return (s12);
}
