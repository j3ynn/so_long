
#include "../so_long.h"

//DA MODIFICARE UN PO DI COSE
void	clear_mat(char **matrix, int height)
{
	int	    j;

	if (!matrix)
		return ;
	j = 0;
	while (j < height)
	{
		if (matrix[j])
			free(matrix[j]);
		j++;
	}
	free(matrix);
}

void	back_free(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx_ptr && game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	if (game->map)
	{
		if (game->map->maps)
			clear_mat(game->map->maps, game->map->height);
			//free(game->map);
	}
	if (game->mapcopy)
		clear_mat(game->mapcopy, game->map->height);
	free(game);
	exit(0);
}

void	save_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->maps[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
			}
			x++;
		}
		y++;
	}
}
