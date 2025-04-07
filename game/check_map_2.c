/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: je <je@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:07:47 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/07 16:11:56 by je               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_path(char **map, int x, int y);
void	find_cord(char **map, int *start_x, int *start_y);

int	check_shape(char **map)
{
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		if (ft_strlen(map[y]) != len)
			return (0);
		y ++;
	}
	return (1);
}

char	**copy_map_pat(t_map *maps)
{
	char	**dupmap;
	int		x;
	int		y;

	dupmap = malloc(sizeof(char *) * maps->height + 1);
	y = 0;
	if (!dupmap)
		return (NULL);
	while (y < maps->height)
	{
		x = 0;
		dupmap[y] = malloc(sizeof(char) * (maps->width + 1));
		if (!dupmap[y])
			return (NULL);
		while (x < maps->width)
		{
			dupmap[y][x] = maps->maps[y][x];
			x++;
		}
		y++;
	}
	return (dupmap);
}

int	check_path(int i, t_map *maps)
{
	char	**dupmap;
	int		y;
	int		x;

	dupmap = copy_map_pat(maps);
	if (dupmap == NULL)
		return (0);
	find_cord(dupmap, &x, &y);
	fill_path(dupmap, x, y);
	while (dupmap[i])
	{
		if (ft_strchr(dupmap[i], 'E') != NULL)
		{
			ft_free_strs(dupmap, 1);
			return (0);
		}
		if (ft_strchr(dupmap[i], 'C') != NULL)
		{
			ft_free_strs(dupmap, 2);
			return (0);
		}
		i ++;
	}
	ft_free_strs(dupmap, 0);
	return (1);
}

void	fill_path(char **map, int x, int y)
{
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		fill_path(map, x, y - 1);
	if (map[y + 1][x] != '1')
		fill_path(map, x, y + 1);
	if (map[y][x - 1] != '1')
		fill_path(map, x - 1, y);
	if (map[y][x + 1] != '1')
		fill_path(map, x + 1, y);
}

void	find_cord(char **map, int *start_x, int *start_y)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		x = 1;
		while (x < len -1)
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return ;
			}
			x ++;
		}
		y ++;
	}
}
