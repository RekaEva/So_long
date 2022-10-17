/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_general.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:11:26 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:25:27 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validation_data(t_list *lines)
{
	t_list	*tmp;
	int		collect;

	tmp = lines;
	while (tmp && tmp->next)
	{
		if ((((t_line *)tmp->content)->lenght)
			!= (((t_line *)tmp->next->content)->lenght))
			ft_error("Error:\nThe map is not rectangular");
		tmp = tmp->next;
	}
	ft_check_the_chars(lines);
	ft_check_the_walls(lines);
	collect = ft_check_position(lines);
	return (collect);
}

t_data	*ft_map_init(char **strs, int width, int collect)
{
	t_data	*map;
	t_mlx	*mlx_data;

	map = ft_calloc(1, sizeof(t_data));
	mlx_data = ft_calloc(1, sizeof(t_mlx));
	if (!map || !mlx_data)
		ft_error("Error:\nmap or mlx_data does not exist\n");
	map->mlx_data = mlx_data;
	map->height = ft_strlen(strs[1]);
	map->width = width;
	map->score = collect;
	map->current_score = 0;
	map->map = strs;
	map->player_pos_x = 0;
	map->player_pos_y = 0;
	map->moves = 0;
	return (map);
}

t_data	*ft_parser(char *fpath, t_data *map)
{
	int		fd_map;
	t_list	*lines;
	char	**strs;
	int		widht;
	int		collect;

	fd_map = ft_open_file(fpath);
	lines = ft_read_file(fd_map);
	if (lines)
	{
		collect = ft_validation_data(lines);
		widht = ft_lstsize(lines);
		strs = ft_get_array(lines, widht);
		ft_lstclear(&lines, free_line);
		if (strs)
		{
			map = ft_map_init(strs, widht, collect);
			if (map)
				return (map);
		}
	}
	return (NULL);
}
