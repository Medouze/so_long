/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:28 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 13:23:27 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_nbr_obj(char c, int y, int x, t_game *game)
{
	if (c == 'P')
	{
		game->nbr_player += 1;
		game->player_pos_y = y;
		game->player_pos_x = x;
	}
	else if (c == 'E')
	{
		game->nbr_exit += 1;
		game->exit_pos_y = y;
		game->exit_pos_x = x;
	}
	else if (c == 'C')
		game->nbr_collectible += 1;
}

void	check_nbr_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!ft_strchr("01CEP", game->map[i][j]))
				ft_error("Non authorized character on map\n", game);
			check_nbr_obj(game->map[i][j], i, j, game);
		}
	}
}

void	check_map_format(t_game *game)
{
	size_t	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->row_len)
			ft_error("Wrong map format\n", game);
		i++;
	}
	i = 0;
	while (i < game->row_len)
	{
		if (game->map[0][i] != '1' || game->map[game->nbr_row - 1][i] != '1')
			ft_error("Map needs to be surrounded by walls\n", game);
		i++;
	}
	i = 0;
	while (i < game->nbr_row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->row_len - 1] != '1')
			ft_error("Map needs to be surrounded by walls\n", game);
		i++;
	}
}

void	check_map(t_game *game)
{
	check_map_format(game);
	check_nbr_chars(game);
	if (game->nbr_player > 1 || game->nbr_player < 1)
		ft_error("Needs only 1 player on map\n", game);
	if (game->nbr_exit > 1 || game->nbr_exit < 1)
		ft_error("Only one exit needed\n", game);
	if (game->nbr_collectible < 1)
		ft_error("Need collectibles on map\n", game);
	if (!find_path(game->player_pos_y, game->player_pos_x, game))
		ft_error("No path available on map\n", game);
}
