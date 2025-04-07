/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: je <je@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:41 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/07 16:03:46 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->copymap = malloc(sizeof(char *) * game->map->height);
	if (!game->copymap)
		return ;
	while (y < game->map->height)
	{
		x = 0;
		game->copymap[y] = malloc(sizeof(char) * (game->map->width + 1));
		if (!game->copymap[y])
			return ;
		while (x < game->map->width)
		{
			game->copymap[y][x] = game->map->maps[y][x];
			x++;
		}
		y++;
	}
}

void	path_map(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map->height || x < 0 || x >= game->map->width)
		return ;
	if (game->copymap[y][x] == '1' || game->copymap[y][x] == '#')
		return ;
	game->copymap[y][x] = '#';
	path_map(game, y, x - 1);
	path_map(game, y - 1, x);
	path_map(game, y, x + 1);
	path_map(game, y + 1, x);
}

void	render_mapcopy(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		ft_printf("%s\n", game->copymap[y]);
		y++;
	}
}

int	check_ce(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->copymap[y][x] == 'C' || game->copymap[y][x] == 'E')
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
	if (check_ce(game))
		return (1);
	else
		return (0);
}
