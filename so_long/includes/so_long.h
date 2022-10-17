/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:59:04 by cpollito          #+#    #+#             */
/*   Updated: 2022/10/17 13:46:26 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h> 
# include <fcntl.h>
# include "../minilibx/mlx.h"

# include "get_next_line.h"
# include "libft.h"

# define ERROR -1
# define ADD 1
# define CONTINUE 0
# define END_F -2
# define WALL "./graphics/sprites/64x64/xpm/wall.xpm"
# define EMPTY "./graphics/sprites/64x64/xpm/empty.xpm"
# define EXIT_CLOSE "./graphics/sprites/64x64/xpm/exit_0.xpm"
# define EXIT_OPEN "./graphics/sprites/64x64/xpm/exit1.xpm"
# define COLLECT_1 "./graphics/sprites/64x64/xpm/collect_1.xpm"
# define COLLECT_2 "./graphics/sprites/64x64/xpm/collect2.xpm"
# define COLLECT_3 "./graphics/sprites/64x64/xpm/collect3.xpm"
# define COLLECT_4 "./graphics/sprites/64x64/xpm/collect4.xpm"
# define PLAYER_UP "./graphics/sprites/64x64/xpm/player1_up.xpm"
# define PLAYER_LEFT "./graphics/sprites/64x64/xpm/player1_left.xpm"
# define PLAYER_RIGHT "./graphics/sprites/64x64/xpm/player1_right.xpm"
# define PLAYER_DOWN "./graphics/sprites/64x64/xpm/player1_down.xpm"
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

typedef struct s_line
{
	char			*str;
	int				lenght;
}		t_line;

typedef struct s_mlx
{
	void	*wall;
	void	*collect[4];
	void	*player;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*exit_open;
	void	*exit_close;
	void	*empty;
}		t_mlx;

typedef struct s_data
{
	int		height;
	int		width;
	int		player_pos_x;
	int		player_pos_y;
	int		score;
	int		current_score;
	char	**map;
	int		moves;
	void	*mlx;
	void	*mlx_win;
	t_mlx	*mlx_data;
}		t_data;

// parse_general
t_data	*ft_parser(char *fpath, t_data *map);

// parse_file
t_list	*ft_read_file(int fd);
char	**ft_get_array(t_list *lines, int size_lines);
int		ft_open_file(char *fpath);

//validation_lines
int		ft_check_position(t_list *map);
void	ft_check_the_chars(t_list *tmp);
void	ft_check_the_walls(t_list *map);

// error
void	ft_error(char *prompt);

//utils
t_line	*ft_line_new(char *str);
void	free_line(void *line);
void	free_array(char **arr);
int		exit_game(t_data *map);
void	print(int move);

// init_image
t_data	*init_image(t_data *map);

// draw
int		draw_the_map(t_data *map);

// move
int		key_hook(int keycode, t_data *map);

#endif
