# ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
#include "libft/libft.h"



typedef struct s_img	t_img;
typedef struct s_game	t_game;
typedef struct s_player	t_player;

//gestione della finestra
typedef struct	s_app
{
	void	*img;
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	char	*map;
} t_app;

//per gestire le immagini
typedef struct	s_img
{
	void	*addr;
	int		width;
	int		height;
	t_img	*img;
} t_img;

//dati  generali del gioco
typedef struct	s_game
{
	void	*pro;
	void	*window;
	int		finished;
	int		moves;
	char	*map;
	t_img	**imgs;
	t_player	*player;
	//t_exit	*exit;
} t_game;

//rapresentazione del giocatore
typedef struct s_player
{
	t_img	*img;
	int	x;
	int	y;
	int	mirror;
} t_player;


void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_strs(char **strs);
//void	init_img(t_game *game);
void	fill_path(char **map, int x, int y);
void	find_cord(char **map, int *start_x, int *start_y);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

char	**ft_strsdup(char **strs);
char	*ft_strchr(const char *str, int s);
char	*ft_strdup(const char *s);

size_t	ft_strlen(const char *str);
size_t	ft_strslen(char **mat);

int		check_path(char **map);
int		check_shape(char **map);
int		check_map(char **map);
int		check_num(char **map);
int		save_num(char c);
int		check_walls_y(char **map);
int		check_walls_x(char *line);

char **get_map();
// GNL utils

#endif
