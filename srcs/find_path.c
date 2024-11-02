/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:56:25 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/02 17:51:47 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	path_collect(char **map, int y, int x, int *collectibles)
{
	if (map[y][x] == '1' || map[y][x] == '9' || map[y][x] == 'E')
		return (0);
	if (map[y][x] == 'C')
		(*collectibles)--;
	map[y][x] = '9';
	path_collect(map, y - 1, x, collectibles);
	path_collect(map, y + 1, x, collectibles);
	path_collect(map, y, x - 1, collectibles);
	path_collect(map, y, x + 1, collectibles);
	return (0);
}

int	path_exit(char **map, int y, int x)
{
	if (y < 0 || x < 0 || map[y] == NULL
		|| map[y][x] == '1' || map[y][x] == '9')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = '9';
	if (path_exit(map, y - 1, x))
		return (1);
	if (path_exit(map, y + 1, x))
		return (1);
	if (path_exit(map, y, x - 1))
		return (1);
	if (path_exit(map, y, x + 1))
		return (1);
	return (0);
}

int	find_path(int y, int x, t_game *game)
{
	char	**cp_map;
	int		collectibles;
	int		found_exit;

	collectibles = game->nbr_collectible;
	cp_map = copy_map(game);
	if (!cp_map)
	{
		free_map(cp_map);
		ft_error("Alocation failed\n", game);
	}
	path_collect(cp_map, y, x, &collectibles);
	free_map(cp_map);
	cp_map = copy_map(game);
	if (!cp_map)
	{
		free_map(cp_map);
		ft_error("Alocation failed\n", game);
	}
	found_exit = path_exit(cp_map, y, x);
	free_map(cp_map);
	if (collectibles == 0 && found_exit)
		return (1);
	return (0);
}
