/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:16:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/23 00:20:30 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->window.mlx, game->window.mlx_window);
	exit(0);
	return (0);
}

int	parse_key(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(game->window.mlx, game->window.mlx_window);
		exit(0);
	}
	if (keycode == 13 || keycode == 119)
		move_up(game);
	if (keycode == 1 || keycode == 115)
		move_down(game);
	if (keycode == 2 || keycode == 100)
		move_right(game);
	if (keycode == 0 || keycode == 97)
		move_left(game);
	if (keycode == 13 || keycode == 119 || keycode == 0 || keycode == 97 || keycode == 1 || keycode == 115 || keycode == 2 || keycode == 100)
		ft_printf("U moved %d times\n", game->total_play);
	if (game->player_pos_x == game->exit_pos_x && game->player_pos_y == game->exit_pos_y)
		close_window(game);
	return (0);
}
