/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:53:58 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 16:11:36 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i]) 
	{
    	free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char *error_msg, char **map)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	free_map(map);
	exit(EXIT_FAILURE);
}

void	init_game(t_game *game, char const *argv)
{
	game->map = parse_map(argv);
	game->nbr_exit = 0;
	game->nbr_player = 0;
}