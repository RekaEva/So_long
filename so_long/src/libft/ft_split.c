/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:23:16 by cpollito          #+#    #+#             */
/*   Updated: 2022/04/05 19:56:16 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char del)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == del)
			i++;
		else
		{
			k++;
			while (str[i] != del && str[i] != '\0')
				i++;
		}
	}
	return (k);
}

static char	*ft_word(char const *str, char del)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != del)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != del)
	{
		word[i] = str[i];
		i++;
	}
	word [i] = '\0';
	return (word);
}

static void	free_all(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

char	**ft_check_malloc(int words)
{
	char			**array_words;

	array_words = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array_words)
		return (NULL);
	return (array_words);
}

char	**ft_split(char const *s, char c)
{
	char			**array_words;
	int				words;
	int				i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	array_words = ft_check_malloc(words);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		array_words[i] = ft_word(s, c);
		if (array_words[i] == NULL)
		{
			free_all(array_words, i);
			return (NULL);
		}
		i++;
		while (*s != '\0' && *s != c)
			s++;
	}
	array_words[i] = NULL;
	return (array_words);
}
