/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:16:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 23:00:39 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.mlx_window);
	exit(0);
	return (0);
}

int	test_keys(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->window.mlx, game->window.mlx_window);
		exit(0);
	}
	if (keycode == 13 || keycode == 119)
	{
		if (game->map[game->player_pos_y - 1][game->player_pos_x] != '1')
		{
			mlx_clear_window(game->window.mlx, game->window.mlx_window);
			game->player_pos_y--;
			game->total_play++;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
			game->map[game->player_pos_y + 1][game->player_pos_x] = '0';
			ft_put_img_map(game);
		}
	}
	if (keycode == 0 || keycode == 97)
        game->total_play++;
    if (keycode == 1 || keycode == 115)
        game->total_play++;
    if (keycode == 2 || keycode == 100)
		game->total_play++;
	if (keycode == 13 || keycode == 119 || keycode == 0 || keycode == 97 || keycode == 1 || keycode == 115 || keycode == 2 || keycode == 100)
		ft_printf("U moved %d times\n", game->total_play);
	return (0);
}
