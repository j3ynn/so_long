/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbellucc <jbellucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:09:35 by jbellucc          #+#    #+#             */
/*   Updated: 2025/04/10 18:29:15 by jbellucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

static void	init_real_game(t_game *game, char **argv)
{
	game->mlx_pointer = mlx_init();
	game->map = ft_calloc(1, sizeof(t_map));
	game->path = argv[1];
	game->c_player = 0;
	game->c_candy = 0;
	game->c_exit = 0;
	game->steps = 0;
}

void	main_2(t_game *game)
{
	if (!game->w_mlx)
		mlx_destroy_window(game->mlx_pointer, game->w_mlx);
	init_imgs(game);
	draw_map(game);
	save_point(game, 'P');
	mlx_hook(game->w_mlx, 2, 1L << 0, move_kays, game);
	mlx_hook(game->w_mlx, 17, 0, exit_hook, game);
	mlx_loop(game->mlx_pointer);
	back_free(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	if (argc != 2 || ft_cmp(argv[1], ".ber"))
		return (ft_printf("not god!\n"), 1);
	if (open(argv[1], O_RDONLY) < 0)
	{
		ft_printf("Error: file not exist!\n");
		free(game);
		return (1);
		
	}
	init_real_game(game, argv);
	map_str(game, open(argv[1], O_RDONLY), 0);
	if (!check_map(game))
		return (1);
	if (!game->mlx_pointer)
		return (1);
	game->w_mlx = mlx_new_window(game->mlx_pointer,
			game->map->width * 32, game->map->height * 32, "slay");
	main_2(game);
	free(game->w_mlx);
	return (0);
}
