/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:11 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/21 17:19:05 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_arg(t_game *game, char const *argv)
{
	game->argv = malloc(strlen(argv) + 1);
    if (!game->argv)
		ft_error("Allocation memoire argv a echoue", game);
    ft_strlcpy(game->argv, argv, strlen(argv) + 1);
}

int main(int argc, char const **argv)
{
	// int		i = 0;
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (argc == 2)
	{
		parse_arg(&game, argv[1]);
		init_game(&game);
		check_map(&game);
		// while (game.map[i])
		// {
		// 	ft_printf("%s", game.map[i]);
		// 	i++;
		// }
		free_map(&game);
	}
	return 0;
}
