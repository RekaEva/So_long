/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:18:09 by cpollito          #+#    #+#             */
/*   Updated: 2022/05/06 16:25:02 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_only_one(t_list *map)
{
	int	i;

	i = 0;
	while (i < ((t_line *)map->content)->lenght)
	{
		if ((((t_line *)map->content)->str[i]) != '1')
			ft_error ("Error:\nThe wall is in the wrong position\n");
		i++;
	}
}

void	ft_check_the_walls(t_list *map)
{
	t_list	*tmp;
	char	*str;

	tmp = map;
	ft_only_one(map);
	map = map->next;
	while (map->next)
	{
		if ((((t_line *)map->content)->str[0]) == '1')
		{
			str = ft_strrchr(((t_line *)map->content)->str, '1');
			if (str[1] != 0)
				ft_error ("Error:\nThe wall is in the wrong position\n");
		}
		else
			ft_error ("Error:\nThe wall is in the wrong position\n");
		map = map->next;
	}
	ft_only_one(map);
}

void	ft_check_the_chars(t_list *tmp)
{
	int		i;

	while (tmp)
	{
		i = 0;
		while (i < ((t_line *)tmp->content)->lenght)
		{
			if ((((t_line *)tmp->content)->str[i]) != '1'
				&& (((t_line *)tmp->content)->str[i]) != '0'
				&& (((t_line *)tmp->content)->str[i]) != 'C'
				&& (((t_line *)tmp->content)->str[i]) != 'E'
				&& (((t_line *)tmp->content)->str[i]) != 'P')
				ft_error("Error:\nThe map has wrong char");
			i++;
		}
		tmp = tmp->next;
	}
}

void	ft_compare(int counter_p, int counter_e, int counter_c)
{
	if (counter_p != 1)
		ft_error("Error:\nThe player's position is incorrect\n");
	if (counter_e < 1)
		ft_error("Error:\nExit position not found\n");
	if (counter_c < 1)
		ft_error("Error:\nCollect position not found\n");
}

int	ft_check_position(t_list *map)
{
	int		i;
	int		counter_p;
	int		counter_e;
	int		counter_c;

	counter_p = 0;
	counter_e = 0;
	counter_c = 0;
	while (map)
	{
		i = 0;
		while (i < ((t_line *)map->content)->lenght)
		{
			if ((((t_line *)map->content)->str[i]) == 'P')
				counter_p++;
			if ((((t_line *)map->content)->str[i]) == 'E')
				counter_e++;
			if ((((t_line *)map->content)->str[i]) == 'C')
				counter_c++;
			i++;
		}
		map = map->next;
	}
	ft_compare(counter_p, counter_e, counter_c);
	return (counter_c);
}
