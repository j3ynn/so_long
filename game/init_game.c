/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:08:25 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 14:08:26 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	all_map(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (0);
	game->map->height = 0;
	game->map->maps = NULL;
	return (1);
}

int	map_str(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	game->map->width = ft_strlen(line) - 1;
	game->map->maps = malloc(sizeof(char *) * (game->map->width + 2));
	if (!game->map->maps)
	{
		free(line);
		return (0);
	}
	while (line)
	{
		game->map->maps[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map->height = i;
	game->map->maps[i] = NULL;
	return (1);
}

int	init_map(t_game *game)
{
	int	fd;

	if (!all_map(game))
		return (0);
	fd = open(game->file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: file not exist!");
		return (0);
	}
	if (!map_str(game, fd, 0))
	{
		free(game->map);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	game_init(t_game *game)
{
	game->c_player = 0;
	game->c_coin = 0;
	game->c_exit = 0;
	game->steps = 0;
	game->wall = NULL;
	game->floor = NULL;
	game->coin = NULL;
	game->player = NULL;
	game->exit = NULL;
	ft_printf("run :)\n");
	return (1);
}

void	save_point(t_game *game, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
