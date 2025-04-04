/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:09:35 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/04 19:43:22 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	init_real_game(t_game *game, char **argv)
{
	game->mlx_ptr = mlx_init();
	game->map = ft_calloc(1, sizeof(t_map));
	game->file_path = argv[1];
	game->c_player = 0;
	game->c_coin = 0;
	game->c_exit = 0;
	game->steps = 0;
}

void	main_2(t_game *game)
{
	if (!game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	init_imgs(game);
	draw_map(game);
	save_point(game, 'P');
	mlx_hook(game->mlx_win, 2, 1L << 0, move_kays, game);
	mlx_hook(game->mlx_win, 17, 0, exit_hook, game);
	mlx_loop(game->mlx_ptr);
	back_free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	if (argc != 2 || ft_cmp(argv[1], ".ber"))
		return (ft_printf("non va bene!\n"), 1);
	init_real_game(game, argv);
	map_str(game, open(argv[1], O_RDONLY), 0);
	if (open(argv[1], O_RDONLY) < 0)
	{
		ft_printf("Error: file not exist!\n");
		return (1);
	}
	if (!check_map(game))
		return (1);
	if (!game->mlx_ptr)
		return (1);
	game->mlx_win = mlx_new_window(game->mlx_ptr,
			game->map->width * 32, game->map->height * 32, "slay");
	main_2(game);
	return (0);
}
