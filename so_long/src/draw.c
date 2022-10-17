/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:17:49 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:04:48 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_collect(t_data *map, int *i, int *j)
{
	static int	ingibitor = 0;
	static int	iterator = 0;

	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->mlx_data->collect[iterator % 4], *j * 64, *i * 64);
	if (ingibitor % 100 == 0)
		iterator++;
	ingibitor++;
}

void	put_image(t_data *map, int *i, int *j)
{
	if (map->map[*i][*j] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->mlx_data->wall, *j * 64, *i * 64);
	if (map->map[*i][*j] == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->mlx_data->empty, *j * 64, *i * 64);
	if (map->map[*i][*j] == 'C')
		put_collect(map, &*i, &*j);
	if (map->map[*i][*j] == 'E')
	{
		if (map->current_score == map->score)
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->mlx_data->exit_open, *j * 64, *i * 64);
		else
			mlx_put_image_to_window(map->mlx, map->mlx_win,
				map->mlx_data->exit_close, *j * 64, *i * 64);
	}
	if (map->map[*i][*j] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->mlx_data->player, *j * 64, *i * 64);
		map->player_pos_x = *j;
		map->player_pos_y = *i;
	}
}

void	print_moves(t_data *map)
{
	char	*str_moves;
	char	*put_str;
	int		x;

	x = (map->height * 64) / 2;
	str_moves = ft_itoa(map->moves);
	put_str = ft_strjoin("Moves: ", str_moves);
	free(str_moves);
	mlx_string_put(map->mlx, map->mlx_win, x,
		map->width * 64 + 8, 0xCC66FF, put_str);
	free(put_str);
}

int	draw_the_map(t_data *map)
{
	int			i;
	int			j;

	mlx_clear_window(map->mlx, map->mlx_win);
	print_moves(map);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			put_image(map, &i, &j);
			j++;
		}
		i++;
	}
	return (0);
}
