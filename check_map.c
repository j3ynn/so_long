#include "so_long.h"

int	check_num(char **map);
int	save_num(char c);
int	check_walls_y(char **map);
int	check_walls_x(char *line);

int	check_map(char **map)
{
	if (!check_shape(map))
		return (0);
	if (!check_walls_y(map))
		return (0);
	if (!check_num(map))
		return (0);
	if (!check_path(map))
		return (0);
	return (1);
}

int	check_num(char **map)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x < len])
		{
			if (ft_strchr("01CEP", map[y][x]) == NULL)
				return (0); //point(0)
			save_num(map[y][x]);
			x ++;
		}
		y ++;
	}
	return (save_num('J'));
}

int	save_num(char c)
{
	static int	col;
	static int	exi;
	static int	str;

	if (c == 'C')
		col ++;
	if (c == 'E')
		exi ++;
	if (c == 'P')
		str ++;

	if (c == 'J')
	{
		if (exi != 1 || str != 1)
			return (0);
		if (col < 1)
			return (0);
	}
	return (1);
}

int	check_walls_y(char **map)
{
	// int	x;
	int	y;
	int	len;

	y = 1;
	len = ft_strlen(map[0]);
	if (!check_walls_x(map[0]))
		return (0);
	while (map[y + 1])
	{
		if (map[y][0] != 1)
			return (0);
		if (map[y][len] != 1)
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
	while (line[x])
	{
		if (line[x] != 1)
			return (0);
		x ++;
	}
	return (1);
}
