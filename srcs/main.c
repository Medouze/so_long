/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:11 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 22:26:00 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char const **argv)
{
	t_game		game;

	ft_bzero(&game, sizeof(game));
	if (argc == 2)
	{
		parse_arg(&game, argv[1]);
		init_game(&game);
		check_map(&game);
		ft_put_img_map(&game);
		mlx_hook(game.window.mlx_window, 17, 0L, &close_window, &game);
		mlx_key_hook(game.window.mlx_window, &test_keys, &game);
		mlx_loop(game.window.mlx);
		free_game(&game);
	}
	return (0);
}
