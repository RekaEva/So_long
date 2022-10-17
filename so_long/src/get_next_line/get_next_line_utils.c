/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:46 by cpollito          #+#    #+#             */
/*   Updated: 2022/04/30 16:23:19 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memmove_gnl(char *dst, char *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!src && !dst)
		return (0);
	while (n > i)
	{
		(dst)[i] = (src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(const char *s1, char const *s2, int len)
{
	char	*s12;
	char	*cs1;
	char	*cs2;
	int		i;
	int		j;

	i = 0;
	cs1 = (char *)s1;
	cs2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s12)
		return (NULL);
	while (*cs1)
		s12[i++] = *cs1++;
	j = 0;
	while (*cs2 && j <= len)
		s12[i++] = cs2[j++];
	s12[i] = '\0';
	return (s12);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

// char	*ft_strjoin(const char *s1, char const *s2)
// {
// 	char	*s12;
// 	char	*cs1;
// 	char	*cs2;
// 	int		i;

// 	i = 0;
// 	cs1 = (char *)s1;
// 	cs2 = (char *)s2;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!s12)
// 		return (NULL);
// 	while (*cs1)
// 		s12[i++] = *cs1++;
// 	while (*cs2)
// 		s12[i++] = *cs2++;
// 	s12[i] = '\0';
// 	return (s12);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
