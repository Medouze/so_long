/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:28 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/21 21:04:41 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_game *game)
{
    int     fd;
    size_t	i;

    fd = open(game->argv, O_RDONLY);
    if (fd < 0) 
		ft_error("Can't open file\n", game);
    game->map = malloc(sizeof(char *) * MAX_LINE);
    if (!game->map) 
		ft_error("Allocation failed\n", game);
    i = 0;
    while ((game->map[i] = get_next_line(fd)) != NULL && i < MAX_LINE)
	{
        i++;
	}
	game->nbr_row = i;
	close(fd);
	null_terminate_rows(game);
}

void	get_positions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_pos_y = i;
				game->player_pos_x = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_pos_y = i;
				game->exit_pos_x = j;
			}
			j++;
		}
		i++;
	}
}

void	check_nbr_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
				ft_error("Caractere non accepte\n", game);
			else if (game->map[i][j] == 'P')
				game->nbr_player += 1;
			else if (game->map[i][j] == 'E')
				game->nbr_exit += 1;
			else if (game->map[i][j] == 'C')
				game->nbr_collectible += 1;
			j++;
		}
		i++;
	}
	game->total_obj = game->nbr_collectible + game->nbr_exit;
}

void	check_rectangle_walls(t_game *game)
{
	size_t	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->row_len)
			ft_error("Map isn't a rectangle\n", game);
		i++;
	}
	i = 0;
	while (i < game->row_len)
	{
		if (game->map[0][i] != '1' || game->map[game->nbr_row - 1][i] != '1')
			ft_error("Map needs to have walls\n", game);
		i++;
	}
	i = 0;
	while (i < game->nbr_row)
	{
		if (game->map[i][0] != '1' || game->map[i][game->row_len - 1] != '1')
			ft_error("Map needs to have walls\n", game);
		i++;
	}
}

void	check_map(t_game *game)
{
	if (!game->map[0])
		ft_error("Empty map", game);
	check_rectangle_walls(game);
	check_nbr_chars(game);
	if (game->nbr_player > 1 || game->nbr_player < 1)
		ft_error("Needs only 1 player on map\n", game);
	if (game->nbr_exit > 1 || game->nbr_exit < 1)
		ft_error("Only one exit needed\n", game);
	if (game->nbr_collectible < 1)
		ft_error("Need collectibles on map\n", game);
	if(find_path(game->cp_map, game->player_pos_y, game->player_pos_x, game) == -1)
		ft_error("No path available on map\n", game);
	ft_printf("MAP OK\n");
}

