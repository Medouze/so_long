/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:53:58 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 17:44:34 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
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
	if (game->argv)
		free(game->argv);
}

void	ft_error(char *error_msg, t_game *game)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	free_map(game);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game)
{
	parse_map(game);
}