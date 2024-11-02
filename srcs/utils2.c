/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:32:09 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/02 17:48:37 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		i = -1;
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

void	free_game(t_game *game)
{
	if (game == NULL)
		return ;
	free_map(game->map);
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
