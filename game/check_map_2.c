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

int	check_path(char **map)
{
	char	**dupmap;
	int	x;
	int	y;
	int	i;

	i = 0;
	dupmap = ft_strsdup(map);
	if (dupmap == NULL)
		return (0);
	find_cord(dupmap, &x, &y);
	fill_path(dupmap, x, y);
	while (dupmap[i])
	{
		if (ft_strchr(dupmap[i], 'E') == NULL)
		{
			ft_free_strs(dupmap);
			return (0);
		}
		if (ft_strchr(dupmap[i], 'C') == NULL)
		{
			ft_free_strs(dupmap);
			return (0);
		}
		i ++;
	}
	ft_free_strs(dupmap);
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
		while (map[y][x < len])
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return;
			}
			x ++;
		}
		y ++;
	}
}
