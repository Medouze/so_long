/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:58:36 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 17:47:17 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_image(t_game *game)
{
	game->image.wall = mlx_xpm_file_to_image(game->window.mlx, "./img/wall.xpm",
			&game->image.image_width, &game->image.image_height);
	game->image.hero = mlx_xpm_file_to_image(game->window.mlx, "./img/hero.xpm",
			&game->image.image_width, &game->image.image_height);
	game->image.coin = mlx_xpm_file_to_image(game->window.mlx, "./img/coin.xpm",
			&game->image.image_width, &game->image.image_height);
	game->image.back = mlx_xpm_file_to_image(game->window.mlx, "./img/back.xpm",
			&game->image.image_width, &game->image.image_height);
	game->image.exit = mlx_xpm_file_to_image(game->window.mlx, "./img/exit.xpm",
			&game->image.image_width, &game->image.image_height);
	if (!game->image.wall || !game->image.hero || !game->image.coin
		|| !game->image.back || !game->image.exit)
		ft_error("Couldnt load image\n", game);
}

void	set_img_map(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->image.wall, j * 32, i * 32);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->image.hero, j * 32, i * 32);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->image.coin, j * 32, i * 32);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->image.back, j * 32, i * 32);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->image.exit, j * 32, i * 32);
}

void	ft_put_img_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			set_img_map(game, i, j);
	}
}
