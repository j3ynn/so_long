
#ifndef SO_LONG_H
# define SO_LONG_H
# include "./utils/utils.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stddef.h>

typedef struct s_map
{
	char	**maps;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	char	*file_path;
	char	**mapcopy;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	int		x;
	int		y;
	int		c_coin;
	int		c_player;
	int		c_exit;
	int		steps;
}	t_game;

void	init_imgs(t_game *game);
void	associate_imgs(t_game *game, int x, int y, char tile);
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

int		exit_hook(t_game *game);
int		move_kays(int keycode, t_game *game);
int		check_CE(t_game *game);
int		check_route(t_game *game);
int		all_map(t_game *game);
int		map_str(t_game *game, int fd);
int		init_map(t_game *game);
int		game_init(t_game *game);
int		check_num(char **map);
int		save_num(char c);
int		check_walls_y(char **map);
int		check_walls_x(char *line);
int		check_map(char **map);
int		check_shape(char **map);
int		check_path(char **map);
#endif
