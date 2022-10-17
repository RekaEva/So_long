/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:05:09 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:05:39 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_line	*ft_line_new(char *str)
{
	t_line	*node;

	node = ft_calloc(1, sizeof(t_line));
	if (node)
	{
		node->str = str;
		node->lenght = ft_strlen(str);
	}
	return (node);
}

void	free_line(void *line)
{
	t_line	*tmp;

	if (line)
	{
		tmp = line;
		free(tmp->str);
		free(tmp);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	exit_game(t_data *map)
{
	free_array(map->map);
	free(map->mlx_data);
	free(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(EXIT_SUCCESS);
}

void	print(int move)
{
	ft_putstr_fd("move ", 1);
	ft_putnbr_fd(move, 1);
	ft_putchar_fd('\n', 1);
}
