
#include "../so_long.h"

void	move_pc(t_game *game, int new_x, int new_y);

int	move_kays(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		back_free(game);
	else if (keycode == 119 || keycode == 13)
	{
		up(game);
		ft_printf("%d\n" , game->c_coin);
		//move_pc(game, game->x, game->y -1);
	}
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
	if (new_x < 0 || new_y < 0 || new_y >= game->map->height || new_x >= game->map->width)
	{
		ft_printf("new x. è %d\n", new_x);
		return;
	}
	if (!game || !game->map || !game->map->maps)
	{
		ft_printf("no no no struttura non inizializzata\n");
		return ;
	}
	if (game->map->maps[new_y][new_x] != '1')
	{
		if (game->map->maps[new_y][new_x] == 'C')
			game->c_coin--;
		if (game->map->maps[new_y][new_x] == 'E' && game->c_coin == 0)
		{
		/*if(game->c_coin != 0)
				return ;*/
				ft_printf("\ncoin :%d\n", game->c_coin);
			ft_printf("hai vinto veramente ? ;)\n");
			back_free(game);
			return ;
		}
		game->steps++;
		game->map->maps[game->y][game->x] = '0';
		game->y = new_y;
		game->x = new_x;
		game->map->maps[new_y][new_x] = 'P';
		ft_printf("movements: %d\n", game->steps);
		ft_printf("diomaranza");
	}
}


