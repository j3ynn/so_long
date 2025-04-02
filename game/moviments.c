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
