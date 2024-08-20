/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:11 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 16:17:22 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char const **argv)
{
	int		i = 0;
	t_game	game;
	
	if (argc == 2)
	{
		init_game(&game, argv[1]);
		check_map(&game);
		while (game.map[i])
		{
			ft_printf("%s", game.map[i]);
			i++;
		}
		free_map(game.map);
	}
	return 0;
}
