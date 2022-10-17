/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:05:17 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:04:44 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_data *map)
{
	int	img_height;
	int	img_width;

	map->mlx_data->player_up = mlx_xpm_file_to_image(map->mlx, PLAYER_UP,
			&img_width, &img_height);
	map->mlx_data->player_left = mlx_xpm_file_to_image(map->mlx, PLAYER_LEFT,
			&img_width, &img_height);
	map->mlx_data->player_right = mlx_xpm_file_to_image(map->mlx, PLAYER_RIGHT,
			&img_width, &img_height);
	map->mlx_data->player_down = mlx_xpm_file_to_image(map->mlx, PLAYER_DOWN,
			&img_width, &img_height);
}

void	collect_init(t_data *map)
{
	int			img_height;
	int			img_width;

	map->mlx_data->collect[0] = mlx_xpm_file_to_image(map->mlx, COLLECT_1,
			&img_width, &img_height);
	map->mlx_data->collect[1] = mlx_xpm_file_to_image(map->mlx, COLLECT_2,
			&img_width, &img_height);
	map->mlx_data->collect[2] = mlx_xpm_file_to_image(map->mlx, COLLECT_3,
			&img_width, &img_height);
	map->mlx_data->collect[3] = mlx_xpm_file_to_image(map->mlx, COLLECT_4,
			&img_width, &img_height);
}

t_data	*init_image(t_data *map)
{
	int	img_height;
	int	img_width;

	map->mlx_data->wall = mlx_xpm_file_to_image(map->mlx, WALL,
			&img_width, &img_height);
	map->mlx_data->empty = mlx_xpm_file_to_image(map->mlx, EMPTY,
			&img_width, &img_height);
	map->mlx_data->exit_close = mlx_xpm_file_to_image(map->mlx, EXIT_CLOSE,
			&img_width, &img_height);
	map->mlx_data->exit_open = mlx_xpm_file_to_image(map->mlx, EXIT_OPEN,
			&img_width, &img_height);
	collect_init(map);
	player_init(map);
	map->mlx_data->player = map->mlx_data->player_up;
	return (map);
}
