/*#include "./minilibx-linux/mlx.h"
#include "so_long.h"

static void	save_img(t_game *game, t_img *img);
static void	create_img(t_game *game, char *path);

void	init_img(t_game *game)
{
	create_img(game, "./maps-graphics/base.png");
	create_img(game, "./maps-graphics/bush.png");
	create_img(game, "./maps-graphics/candy.png");
	create_img(game, "./maps-graphics/kid1.png");
	create_img(game, "./maps-graphics/kid2.png");
	create_img(game, "./maps-graphics/kid3.png");
	create_img(game, "./maps-graphics/van.png");
}

//questa funzione serve a associare le immagini a un carattere
static void	create_img(t_game *game, char *path)
{
	t_img	*img;

	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(game->pro, path, &img->width,
			&img->height);
	if (!img->addr)
	{
		free(img);
		return (NULL); //da modificare perchè qui devi printare l'errore
	}
	save_img(game, img);
}

static void	save_img(t_game *game, t_img *img)
{
	int	j;

	j = 0;
	if (!game->imgs)
	{
		game->imgs = ft_calloc(40, sizeof(t_img *));
		if (!game->imgs)
			return (0); //da modificare perchè qui devi printare l'errore
	}
	while (game->imgs[j] != NULL)
		j ++;
	game->imgs = img;
}*/
