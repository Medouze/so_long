/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:53:58 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/22 23:03:46 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	i = 0;
	if (game->cp_map)
	{
		while (game->cp_map[i])
		{
			free(game->cp_map[i]);
			i++;
		}
		free(game->cp_map);
	}
	if (game->argv)
		free(game->argv);
}

void	ft_error(char *error_msg, t_game *game)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	free_game(game);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	get_nbr_row(game);
	parse_map(game);
	cp_map(game);
	game->row_len = ft_strlen(game->map[0]);
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
		ft_error("Allocation failed\n", game);
	game->window.mlx_window = mlx_new_window(game->window.mlx,
			game->row_len * 32, game->nbr_row * 32, "My game");
	if (!game->window.mlx_window)
		ft_error("Allocation failed\n", game);
	init_image(game);
}

void	null_terminate_rows(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '\n')
			{
				game->map[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}
