/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:11 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/02 17:43:19 by mlavergn         ###   ########.fr       */
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
		ft_put_img_map(&game);
		mlx_hook(game.window.mlx_window, 17, 0L, &close_window, &game);
		mlx_key_hook(game.window.mlx_window, &parse_key, &game);
		mlx_loop(game.window.mlx);
	}
	else
		ft_error("Only one argument needed\n", &game);
	return (0);
}
