/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:37 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 18:43:22 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_imgs(t_game *game)
{
	int	width;
	int	height;

	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./graphics/base.xpm",
			&width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./graphics/bush.xpm",
			&width, &height);
	game->coin = mlx_xpm_file_to_image(game->mlx_ptr, "./graphics/candy.xpm",
			&width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./graphics/kid1.xpm",
			&width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./graphics/van.xpm",
			&width, &height);
}

void	associate_imgs(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->wall, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->floor, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->player, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->coin, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

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
