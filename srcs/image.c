/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 00:58:36 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 03:02:30 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_image(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->window.mlx, "./img/wall.xpm",
			&game->img.width, &game->img.height);
	game->img.hero = mlx_xpm_file_to_image(game->window.mlx, "./img/ldown.xpm",
			&game->img.width, &game->img.height);
	game->img.coin = mlx_xpm_file_to_image(game->window.mlx, "./img/coin.xpm",
			&game->img.width, &game->img.height);
	game->img.back = mlx_xpm_file_to_image(game->window.mlx, "./img/back.xpm",
			&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->window.mlx, "./img/exit.xpm",
			&game->img.width, &game->img.height);
	if (!game->img.wall || !game->img.hero || !game->img.coin
		|| !game->img.back || !game->img.exit)
		ft_error("Couldnt load image\n", game);
}

void	set_img_map(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->img.wall, j * 32, i * 32);
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->img.hero, j * 32, i * 32);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->img.coin, j * 32, i * 32);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->img.back, j * 32, i * 32);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->window.mlx,
			game->window.mlx_window, game->img.exit, j * 32, i * 32);
	draw_text(game);
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

void	draw_text(t_game *game)
{
	int		color;
	char	*swords;
	char	*count_collectibles;
	size_t	text_len;

	color = 0xFFFFFF;
	swords = ft_itoa(game->nbr_collectible);
	text_len = strlen("Collectables left : ") + (strlen(swords) + 1);
	count_collectibles = malloc(text_len);
	if (!count_collectibles)
	{
		free(swords);
		return ;
	}
	strcpy(count_collectibles, "Collectables left : ");
	strcat(count_collectibles, swords);
	mlx_string_put(game->window.mlx,
		game->window.mlx_window, 10, 20, color, count_collectibles);
	free(count_collectibles);
	free(swords);
}
