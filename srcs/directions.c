/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:32:22 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 23:55:06 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->player_pos_y - 1][game->player_pos_x] != '1')
	{
		if (!(game->map[game->player_pos_y - 1][game->player_pos_x] == 'E' && game->nbr_collectible != 0))
		{
			if(game->map[game->player_pos_y - 1][game->player_pos_x] == 'C')
				game->nbr_collectible--;
			mlx_clear_window(game->window.mlx, game->window.mlx_window);
			game->player_pos_y--;
			game->total_play++;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
			game->map[game->player_pos_y + 1][game->player_pos_x] = '0';
			ft_put_img_map(game);
		}

	}
}
void	move_down(t_game *game)
{
	if (game->map[game->player_pos_y + 1][game->player_pos_x] != '1')
	{
		if (!(game->map[game->player_pos_y + 1][game->player_pos_x] == 'E' && game->nbr_collectible != 0))
		{
			if(game->map[game->player_pos_y + 1][game->player_pos_x] == 'C')
				game->nbr_collectible--;
			mlx_clear_window(game->window.mlx, game->window.mlx_window);
			game->player_pos_y++;
			game->total_play++;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
			game->map[game->player_pos_y - 1][game->player_pos_x] = '0';
			ft_put_img_map(game);
		}

	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x + 1] != '1')
	{
		if (!(game->map[game->player_pos_y ][game->player_pos_x + 1] == 'E' && game->nbr_collectible != 0))
		{
			if(game->map[game->player_pos_y][game->player_pos_x + 1] == 'C')
				game->nbr_collectible--;
			mlx_clear_window(game->window.mlx, game->window.mlx_window);
			game->player_pos_x++;
			game->total_play++;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
			game->map[game->player_pos_y][game->player_pos_x - 1] = '0';
			ft_put_img_map(game);
		}

	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_pos_y][game->player_pos_x + - 1] != '1')
	{
		if (!(game->map[game->player_pos_y ][game->player_pos_x - 1] == 'E' && game->nbr_collectible != 0))
		{
			if(game->map[game->player_pos_y][game->player_pos_x - 1] == 'C')
				game->nbr_collectible--;
			mlx_clear_window(game->window.mlx, game->window.mlx_window);
			game->player_pos_x--;
			game->total_play++;
			game->map[game->player_pos_y][game->player_pos_x] = 'P';
			game->map[game->player_pos_y][game->player_pos_x + 1] = '0';
			ft_put_img_map(game);
		}
	}
}