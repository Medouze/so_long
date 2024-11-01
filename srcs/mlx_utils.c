/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:16:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/01 21:59:14 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_game *game)
{
	if (game->img.hero)
		mlx_destroy_image(game->window.mlx, game->img.hero);
	if (game->img.coin)
		mlx_destroy_image(game->window.mlx, game->img.coin);
	if (game->img.exit)
		mlx_destroy_image(game->window.mlx, game->img.exit);
	if (game->img.wall)
		mlx_destroy_image(game->window.mlx, game->img.wall);
	if (game->img.back)
		mlx_destroy_image(game->window.mlx, game->img.back);
	if (game->window.mlx_window)
		mlx_destroy_window(game->window.mlx, game->window.mlx_window);
	if (game->window.mlx)
		mlx_destroy_display(game->window.mlx);
	if (game)
		free_game(game);
	exit(0);
	return (0);
}

int	parse_key(int keycode, t_game *game)
{
	int	previous_play;

	previous_play = game->total_play;
	if (keycode == 13 || keycode == 119)
		move_up(game);
	if (keycode == 1 || keycode == 115)
		move_down(game);
	if (keycode == 2 || keycode == 100)
		move_right(game);
	if (keycode == 0 || keycode == 97)
		move_left(game);
	if (keycode == 53 || keycode == 65307)
		close_window(game);
	if (game->player_pos_x == game->exit_pos_x
		&&game->player_pos_y == game->exit_pos_y && game->nbr_collectible == 0)
	{
		ft_printf("U moved %d times\n", game->total_play);
		close_window(game);
	}
	if (previous_play != game->total_play)
		ft_printf("U moved %d times\n", game->total_play);
	return (0);
}
