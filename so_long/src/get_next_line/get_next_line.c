/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:10:50 by cpollito          #+#    #+#             */
/*   Updated: 2022/04/30 16:02:34 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(char *buf, char **str, int *buf_exist)
{
	int			p_n;
	int			len_buf;
	char		*tmp;

	p_n = ft_strchr_gnl(buf, '\n');
	if (p_n >= 0)
	{
		tmp = *str;
		*str = ft_strjoin_gnl(*str, buf, p_n);
		if (*tmp)
			free(tmp);
		if (buf[p_n + 1] != '\0')
		{
			*buf_exist = 1;
			len_buf = ft_strlen(buf);
			ft_memmove_gnl(buf, buf + (p_n + 1), (len_buf - (p_n + 1)));
		}
		else
			*buf_exist = 0;
		return (1);
	}
	return (0);
}

char	*ft_join_and_free(char **str, char *buf)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strjoin(*str, buf);
	if (*tmp)
		free(tmp);
	return (*str);
}

char	*ft_reading(int fd, int *byte_was_read, char *buf)
{
	*byte_was_read = read(fd, buf, BUFFER_SIZE);
	buf[*byte_was_read] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	buf_exist;
	char		*str;
	int			byte_was_read;

	if (fd < 0 || (read(fd, buf, 0) == -1))
		return (NULL);
	str = "\0";
	byte_was_read = 1;
	if (!buf_exist)
		ft_reading(fd, &byte_was_read, buf);
	if (byte_was_read == 0)
		return (NULL);
	while (byte_was_read)
	{
		if (find_n(buf, &str, &buf_exist))
			return (str);
		ft_join_and_free (&str, buf);
		ft_reading(fd, &byte_was_read, buf);
		if (byte_was_read == 0)
			buf_exist = 0;
	}
	return (str);
}
