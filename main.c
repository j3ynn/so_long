#include "so_long.h"
#include "mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2 || ft_cmp(argv[1], ".ber"))
		return (ft_printf("non va bene!\n"), 1);
	game = ft_calloc(1 , sizeof(t_game));
	if (!game)
		return (1);
	game->map = ft_calloc(1, sizeof(t_map));
	game->file_path = argv[1];
	map_str(game, open(argv[1], O_RDONLY));
	check_map(game->map->maps);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	return (1);
	game->mlx_win = mlx_new_window(game->mlx_ptr,
		game->map->width * 32, game->map->height * 32,
		"slay");
	ft_printf("ho superato slay");
	if (!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	init_imgs(game);
	draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, move_kays, game);
	mlx_hook(game->mlx_win, 17, 0, exit_hook, game);
	mlx_loop(game->mlx_ptr);
	back_free(game);
	return (0);
}
