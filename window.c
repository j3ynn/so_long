#include "./minilibx-linux/mlx.h"
#include "so_long.h"

void	app_init(t_app *app)
{
	app->width = 500;
	app->height = 500;
	app->mlx = mlx_init();
	app->window = mlx_new_window(app->mlx, app->width, app->height, "so_long");
}

int main()
{
	t_app	app;

	char	matrice[7][14] =
	{
		{'1','1','1','1','1','1','1','1','1','1','1','1','1','\0'},
		{'1','0','0','0','0','0','1','0','0','0','0','1','1', '\0'},
		{'1','0','1','1','1','0','0','0','1','1','0','C','1', '\0'},
		{'1','0','C','1','1','1','1','1','1','0','0','1','1', '\0'},
		{'1','P','1','E','0','0','0','0','0','0','1','1','1', '\0'},
		{'1','1','1','1','1','1','1','1','1','1','1','1','1', '\0'},
		{'\0'},
	};

	char **mat = get_map();
	if (check_map((char **)matrice))
		printf("si\n");
	else
		printf("no\n");


/*
	app_init(&app);
	mlx_new_image(app.mlx, app.width, app.height);
	//init_img(&app);
	mlx_loop(app.mlx);*/
	return (0);
}

