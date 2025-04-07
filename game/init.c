/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:21:46 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/07 16:21:47 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_init(t_game *game)
{
	game->floor = NULL;
	game->wall = NULL;
	game->candy = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->c_exit = 0;
	game->steps = 0;
	game->c_player = 0;
	game->c_candy = 0;
	ft_printf("run :)\n");
	return (1);
}

void	save_point(t_game *game, char c)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map->maps[x])
	{
		y = 0;
		while (game->map->maps[x][y])
		{
			if (game->map->maps[x][y] == c)
			{
				game->x = y;
				game->y = x;
				return ;
			}
			y++;
		}
		x++;
	}
	return ;
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			associate_imgs(game, x * 32, y * 32, game->map->maps[y][x]);
			x++;
		}
		y++;
	}
}
