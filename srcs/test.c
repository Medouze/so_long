/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:16:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 02:15:21 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
    {
        mlx_destroy_window(game->window.mlx, game->window.mlx_window);
        exit(0);
    }
	exit(0);
    return (0);
}