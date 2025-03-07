#include "mlx/mlx.h"
#include "so_long.h"
#include <fcntl.h>

static void ft_print_strs(char **strs);

void	app_init(t_app *app)
{
	app->width = 500;
	app->height = 500;
	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx, app->width, app->height, "so_long");
}

int main()
{
	// t_app	app;
	int i = 6;
	int j = 0;
	int fd = open("map.ber",O_RDONLY);
	printf("%i\n",fd);
	char **map = ft_calloc(40,sizeof(char *));

	while(i)
	{
		map[j] = get_next_line(fd);
		printf("%s",map[j]);
		i--;
		j++;
	}
	ft_print_strs(map);
	// if (check_map((char **)matrice))
	// 	printf("si\n");
	// else
	// 	printf("no\n");

	// app_init(&app);
	// mlx_new_image(app.mlx, app.width, app.height);
	// mlx_loop(app.mlx);
	return (0);
}

static void ft_print_strs(char **strs)
{
	int i = 0;
	while(strs && strs[i])
	{
		printf("%s\n",strs[i]);
		i++;
	}
}
