/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:45 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/10 18:39:21 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_pc(t_game *game, int new_x, int new_y);

int	move_kays(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		back_free(game);
	else if (keycode == 119 || keycode == 65362)
	{
		up(game);
	}
	else if (keycode == 115 || keycode == 65364)
		down(game);
	else if (keycode == 97 || keycode == 65361)
		left(game);
	else if (keycode == 100 || keycode == 65363)
		right(game);
	draw_map(game);
	return (0);
}

void	move_pc(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_y >= game->map->height
		|| new_x >= game->map->width)
		return ;
	if (game->map->maps[new_y][new_x] != '1')
	{
		if (game->map->maps[new_y][new_x] == 'C')
			game->c_candy--;
		if (game->map->maps[new_y][new_x] == 'E')
		{
			if (game->c_candy == 0)
			{
				ft_printf("did you really win? ;)\n");
				back_free(game);
				return ;
			}
		}
		move_pc2(game, new_x, new_y);
	}
}

void	move_pc2(t_game *game, int new_x, int new_y)
{
	{
		if (game->map->maps[new_y][new_x] == 'E' && game->c_candy != 0)
			ft_printf("take the candy! :(\n");
		else
		{
			game->steps++;
			game->map->maps[game->y][game->x] = '0';
			game->y = new_y;
			game->x = new_x;
			game->map->maps[new_y][new_x] = 'P';
			ft_printf("movements: %d\n", game->steps);
		}
	}
}
