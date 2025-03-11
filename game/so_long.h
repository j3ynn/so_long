#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**maps;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map	*map;
	char	**mapcopy;
	void	*mlx_ptr;
	void	*mlx_win;
	char	*file_path;
	int		x;
	int		y;
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
	int		c_coin;
	int		c_player;
	int		c_exit;
	int		steps;
}	t_game;

void    fill_path(char **map, int x, int y);
void    find_cord(char **map, int *start_x, int *start_y);
int     check_shape(char **map);
int     check_path(char **map);
int     check_num(char **map);
int     save_num(char c);
int     check_walls_y(char **map);
int     check_walls_x(char *line);


#endif
