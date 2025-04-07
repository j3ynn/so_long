/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: je <je@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:09:46 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/07 16:10:11 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./utils/utils.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map
{
	char	**maps;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	char	*path;
	char	**copymap;
	void	*mlx_pointer;
	void	*w_mlx;
	void	*wall;
	void	*floor;
	void	*player;
	void	*candy;
	void	*exit;
	int		x;
	int		y;
	int		c_candy;
	int		c_player;
	int		c_exit;
	int		steps;
}	t_game;

void	init_imgs(t_game *game);
void	associate_imgs(t_game *game, int x, int y, char chctr);
void	draw_map(t_game *game);
void	back_free(t_game *game);
void	save_position(t_game *game);
void	move_pc(t_game *game, int new_x, int new_y);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
void	copy_map(t_game *game);
void	render_mapcopy(t_game *game);
void	fill_path(char **map, int x, int y);
void	find_cord(char **map, int *start_x, int *start_y);
void	fill_path(char **map, int x, int y);
void	find_cord(char **map, int *start_x, int *start_y);
void	clean_img(t_game *game);
void	save_point(t_game *game, char c);
void	save_num(char c, t_game *game);
void	move_pc2(t_game *game, int new_x, int new_y);

int		exit_hook(t_game *game);
int		move_kays(int keycode, t_game *game);
int		check_ce(t_game *game);
int		check_route(t_game *game);
int		all_map(t_game *game);
int		map_str(t_game *game, int fd, int i);
int		init_map(t_game *game);
int		game_init(t_game *game);
int		check_num(t_game *game);
int		check_walls_y(char **map);
int		check_walls_x(char *line);
int		check_map(t_game *game);
int		check_shape(char **map);
int		check_path(int i, t_map *maps);
#endif
