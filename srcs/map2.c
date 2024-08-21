/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:42:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/21 21:04:16 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	cp_map(t_game *game)
{
	int		i;
	int		j;

	game->cp_map = malloc(sizeof(char *) * (game->nbr_row + 1));
	if (!game->cp_map)
		return ;
	game->cp_map[game->nbr_row] = NULL;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		game->cp_map[i] = malloc(sizeof(char) * (ft_strlen(game->map[i]) + 1));
		if (!game->cp_map[i])
			return ;
		while (game->map[i][++j])
			game->cp_map[i][j] = game->map[i][j];
		game->cp_map[i][j] = '\0';
	} 
}

int	find_path(char **map, int y, int x, t_game *game)
{
	char		direction[4];
	static int	collectibles;

	if (y == game->player_pos_y && x == game->player_pos_x)
		collectibles = game->total_obj;
	direction[UP] = map[y - 1][x];
	direction[DOWN] = map[y + 1][x];
	direction[LEFT] = map[y][x - 1];
	direction[RIGHT] = map[y][x + 1];
	if (map[y][x] == 'C' || map[y][x] == 'E')
		collectibles--;
	map[y][x] = '9';
	if (direction[UP] != '1' && direction[UP] != '9')
		find_path(map, y - 1, x, game);
	if (direction[DOWN] != '1' && direction[DOWN] != '9')
		find_path(map, y + 1, x, game);
	if (direction[LEFT] != '1' && direction[LEFT] != '9')
		find_path(map, y, x - 1, game);
	if (direction[RIGHT] != '1' && direction[RIGHT] != '9')
		find_path(map, y, x + 1, game);
	if (collectibles == 0)
		return (0);
	return (-1);
}
