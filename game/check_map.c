#include "../so_long.h"
#include "stdio.h"

int	check_num(t_game *game)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(game->map->maps[0]);
	y = 0;
	while ((size_t)y < ft_strslen(game->map->maps))
	{
		x = 0;
		while (x < len-1)
		{

			if (game->map->maps[y][x] != 'C' && game->map->maps[y][x] != 'E'
				&& game->map->maps[y][x] != 'P' && game->map->maps[y][x] != '0'
				&& game->map->maps[y][x] != '1')
				return (0);
			save_num(game->map->maps[y][x], game);
			x ++;
		}
		y ++;
	}
	return (1);
}

void	save_num(char c, t_game *game)
{
	if (c == 'C')
		game->c_coin++;
	if (c == 'E')
		game->c_exit++;
	if (c == 'P')
	{
		game->c_player++;
		ft_printf("COIN TOTAL:%d", game->c_coin);
		ft_printf("COIN TOTAL:%d", game->c_player);
	}
}

int	check_walls_y(char **map)
{
	int	y;
	int	len;

	y = 1;
	len = ft_strlen(map[0]);
	if (!check_walls_x(map[0]))
		return (0);
	while (map[y + 1])
	{
		//printf("%c %c --- \n",map[y][0],map[y][len -2]);
		if (map[y][0] != '1')
			return (0);
		if (map[y][len - 2] != '1')
			return (0);
		y ++;
	}

	if (!check_walls_x(map[y]))
		return (0);
	return (1);
}

int	check_walls_x(char *line)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] != '1')
			return (0);
		x ++;
	}
	return (1);
}

int	check_map(t_game *game)
{

	if (!check_shape(game->map->maps))
		return (0);
	if (!check_walls_y(game->map->maps))
		return (0);
	if (!check_num(game))
		return (0);
	if (!check_path(game->map->maps))
		return (0);
	return (1);
}
