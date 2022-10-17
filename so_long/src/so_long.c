/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:57:49 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:23:30 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_main_mlx(t_data *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		ft_error("Error:\nmlx does't init\n");
	map->mlx_win = mlx_new_window(map->mlx,
			map->height * 64, map->width * 64 + 32, "So_long!");
	map = init_image(map);
	mlx_hook(map->mlx_win, 17, 0,
		exit_game, map);
	mlx_hook(map->mlx_win, 2, 0, key_hook, map);
	mlx_loop_hook(map->mlx, draw_the_map, map);
	mlx_loop(map->mlx);
	mlx_destroy_window(map->mlx, map->mlx_win);
}

int	main(int argc, char **argv)
{
	t_data	*map;

	if (argc == 2)
	{
		map = NULL;
		map = ft_parser(argv[1], map);
		if (!map)
			ft_error("Error:\nmap does not exist\n");
		ft_main_mlx(map);
		free_array(map->map);
		free(map->mlx_data);
		free(map);
		return (0);
	}
	else
		ft_error("Error:\ninvalid of arguments\n");
	return (0);
}
