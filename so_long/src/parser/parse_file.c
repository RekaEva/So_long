/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:41 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:25:43 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_file(char *fpath)
{
	char	*str;
	int		fd;

	str = ft_strrchr(fpath, '.');
	if (!str)
		ft_error("Error:\nno .ber extension\n");
	if (ft_strcmp(str, ".ber") != 0)
		ft_error("Error:\nwrong extension\n");
	fd = open(fpath, O_RDONLY | O_CLOEXEC);
	if (fd < 0)
		ft_error("Error:\ncannot open file.\n");
	return (fd);
}

char	**ft_get_array(t_list *lines, int size_lines)
{
	char	**strs;
	int		i;

	strs = ft_calloc(size_lines + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (lines)
	{
		strs[i] = ft_strdup(((t_line *)lines->content)->str);
		if (!strs[i])
		{
			free_array(strs);
			return (NULL);
		}
		i++;
		lines = lines->next;
	}
	strs[i] = NULL;
	return (strs);
}

int	check_str(char *str, int fd_map)
{
	if (read(fd_map, str, 0) > 0)
		return (ERROR);
	return (END_F);
}

int	get_node(int fd_map, t_list **tmp)
{
	char	*trimstr;
	t_line	*line;
	char	*str;

	str = get_next_line(fd_map);
	if (!str)
		return (check_str(str, fd_map));
	trimstr = ft_strtrim(str, " \n\t\v\r\f");
	free(str);
	if (!trimstr)
		return (ERROR);
	if (*trimstr)
	{
		line = ft_line_new(trimstr);
		if (line)
		{
			*tmp = ft_lstnew(line);
			return (ADD);
		}
		free(trimstr);
		return (-1);
	}
	free(trimstr);
	return (CONTINUE);
}

t_list	*ft_read_file(int fd)
{
	t_list	*tmp;
	t_list	*lines;
	int		status;

	lines = NULL;
	while (true)
	{
		tmp = NULL;
		status = get_node(fd, &tmp);
		if (status == END_F)
			break ;
		if (status == ADD)
		{
			ft_lstadd_back(&lines, tmp);
			continue ;
		}
		if (status == CONTINUE)
			continue ;
		ft_lstclear(&lines, free_line);
		lines = NULL;
		break ;
	}	
	return (lines);
}
