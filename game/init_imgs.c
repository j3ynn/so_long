/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:37 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/07 16:38:50 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_imgs(t_game *game)
{
	int	height;
	int	width;

	game->floor = mlx_xpm_file_to_image(game->mlx_pointer,
			"./graphics/base.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_pointer,
			"./graphics/bush.xpm", &width, &height);
	game->candy = mlx_xpm_file_to_image(game->mlx_pointer,
			"./graphics/candy.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_pointer,
			"./graphics/kid1.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx_pointer,
			"./graphics/van.xpm", &width, &height);
}

void	associate_imgs(t_game *game, int x, int y, char chctr)
{
	if (chctr == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->w_mlx,
			game->wall, x, y);
	else if (chctr == '0')
		mlx_put_image_to_window(game->mlx_pointer, game->w_mlx,
			game->floor, x, y);
	else if (chctr == 'P')
		mlx_put_image_to_window(game->mlx_pointer, game->w_mlx,
			game->player, x, y);
	else if (chctr == 'C')
		mlx_put_image_to_window(game->mlx_pointer,
			game->w_mlx, game->candy, x, y);
	else if (chctr == 'E')
		mlx_put_image_to_window(game->mlx_pointer,
			game->w_mlx, game->exit, x, y);
}
