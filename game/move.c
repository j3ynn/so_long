
#include "../so_long.h"

int	move_kays(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		back_free(game);
	else if (keycode == 119 || keycode == 13)
		up(game);
	else if (keycode == 115 || keycode == 1)
		down(game);
	else if (keycode == 97 || keycode == 0)
		left(game);
	else if (keycode == 100 || keycode == 2)
		right(game);
	draw_map(game);
	return (0);
}

int	exit_hook(t_game *game)
{
	back_free(game);
	return (0);
}

void	move_pc(t_game *game, int new_x, int new_y)
{
	if (!game || !game->map || !game->map->maps)
	{
		ft_printf("no no no struttura non inizializzata\n");
		return ;
	}
	if (game->map->maps[new_y][new_x] != '1')
	{
		if (game->map->maps[new_y][new_x] == 'C')
			game->c_coin--;
		if (game->map->maps[new_y][new_x] == 'E')
		{
			if (game->c_coin)
				return ;
			ft_printf("hai vinto veramente ? ;)\n");
			back_free(game);
		}
		game->steps++;
		game->map->maps[game->y][game->x] = '0';
		game->y = new_y;
		game->x = new_x;
		game->map->maps[new_y][new_x] = 'P';
		ft_printf("movements: %d\n", game->steps);
	}
}

void	up(t_game *game)
{
	move_pc(game, game->x, game->y - 1);
}

void	down(t_game *game)
{
	move_pc(game, game->x, game->y + 1);
}

void	left(t_game *game)
{
	move_pc(game, game->x - 1, game->y);
}

void	right(t_game *game)
{
	move_pc(game, game->x + 1, game->y);
}


