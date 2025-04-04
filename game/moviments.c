/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:49 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 18:47:18 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	exit_hook(t_game *game)
{
	back_free(game);
	return (0);
}
