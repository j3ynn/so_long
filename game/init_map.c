#include "../so_long.h"

void	copy_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->mapcopy = malloc(sizeof(char *) * game->map->height);
	if (!game->mapcopy)
		return ;
	while (y < game->map->height)
	{
		x = 0;
		game->mapcopy[y] = malloc(sizeof(char) * (game->map->width + 1));
		if (!game->mapcopy[y])
			return ;
		while (x < game->map->width)
		{
			game->mapcopy[y][x] = game->map->maps[y][x];
			x++;
		}
		y++;
	}
}

void	path_map(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width)
		return ;
	if (game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == '#')
		return ;
	game->mapcopy[y][x] = '#';
	path_map(game, y - 1, x);
	path_map(game, y, x - 1);
	path_map(game, y + 1, x);
	path_map(game, y, x + 1);
}

void	render_mapcopy(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		ft_printf("%s\n", game->mapcopy[y]);
		y++;
	}
}

int	check_CE(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->mapcopy[y][x] == 'C' || game->mapcopy[y][x] == 'E')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_route(t_game *game)
{
	copy_map(game);
	save_position(game);
	path_map(game, game->y, game->x);
	if (check_CE(game))
		return (1);
	else
		return (0);
}
