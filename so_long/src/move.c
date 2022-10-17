/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:21:32 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:04:40 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *map)
{
	map->mlx_data->player = map->mlx_data->player_up;
	if (map->map[map->player_pos_y - 1][map->player_pos_x] != '1')
	{
		if (map->map[map->player_pos_y - 1][map->player_pos_x] == 'C')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y - 1][map->player_pos_x] = 'P';
			map->current_score = map->current_score + 1;
		}
		else if (map->map[map->player_pos_y - 1][map->player_pos_x] == '0')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y - 1][map->player_pos_x] = 'P';
		}
		else if (map->map[map->player_pos_y - 1][map->player_pos_x] == 'E'
				&& map->current_score == map->score)
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y - 1][map->player_pos_x] = 'P';
			exit_game(map);
		}
	}
	map->moves = map->moves + 1;
	map->player_pos_y = map->player_pos_y - 1;
	print(map->moves);
}

void	move_down(t_data *map)
{
	map->mlx_data->player = map->mlx_data->player_down;
	if (map->map[map->player_pos_y + 1][map->player_pos_x] != '1')
	{
		if (map->map[map->player_pos_y + 1][map->player_pos_x] == 'C')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y + 1][map->player_pos_x] = 'P';
			map->current_score = map->current_score + 1;
		}
		else if (map->map[map->player_pos_y + 1][map->player_pos_x] == '0')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y + 1][map->player_pos_x] = 'P';
		}
		else if (map->map[map->player_pos_y + 1][map->player_pos_x] == 'E'
				&& map->current_score == map->score)
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y + 1][map->player_pos_x] = 'P';
			exit_game(map);
		}
	}
	map->moves = map->moves + 1;
	map->player_pos_y = map->player_pos_y + 1;
	print(map->moves);
}

void	move_left(t_data *map)
{
	map->mlx_data->player = map->mlx_data->player_left;
	if (map->map[map->player_pos_y][map->player_pos_x - 1] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x -1] == 'C')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x - 1] = 'P';
			map->current_score = map->current_score + 1;
		}
		else if (map->map[map->player_pos_y][map->player_pos_x - 1] == '0')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x - 1] = 'P';
		}
		else if (map->map[map->player_pos_y][map->player_pos_x - 1] == 'E'
				&& map->current_score == map->score)
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x - 1] = 'P';
			exit_game(map);
		}
	}
	map->moves = map->moves + 1;
	map->player_pos_x = map->player_pos_x - 1;
	print(map->moves);
}

void	move_right(t_data *map)
{
	map->mlx_data->player = map->mlx_data->player_right;
	if (map->map[map->player_pos_y][map->player_pos_x + 1] != '1')
	{
		if (map->map[map->player_pos_y][map->player_pos_x + 1] == 'C')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x + 1] = 'P';
			map->current_score = map->current_score + 1;
		}
		else if (map->map[map->player_pos_y][map->player_pos_x + 1] == '0')
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x + 1] = 'P';
		}
		else if (map->map[map->player_pos_y][map->player_pos_x + 1] == 'E'
				&& map->current_score == map->score)
		{
			map->map[map->player_pos_y][map->player_pos_x] = '0';
			map->map[map->player_pos_y][map->player_pos_x + 1] = 'P';
			exit_game(map);
		}
	}
	map->moves = map->moves + 1;
	map->player_pos_x = map->player_pos_x + 1;
	print(map->moves);
}

int	key_hook(int keycode, t_data *map)
{
	if (keycode == ESC)
		return (exit_game(map));
	if (keycode == W)
		move_up(map);
	if (keycode == S)
		move_down(map);
	if (keycode == A)
		move_left(map);
	if (keycode == D)
		move_right(map);
	return (0);
}
