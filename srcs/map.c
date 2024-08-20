/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:28 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 17:43:01 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_game *game)
{
    int     fd;
    int     i;

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
}

void	check_mapchars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P' && game->map[i][j] != '\n')
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
}
// void	check_col_nbr(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j])
// 		{

// 		}
// 	}
// }

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != '\n')
			ft_error("La map n'est pas entoure de murs\n", game);
		i++;
	}
	i = 0;
	while (game->map[game->nbr_row - 1][i])
	{
		if (game->map[game->nbr_row - 1][i] != '1' && game->map[game->nbr_row - 1][i] != '\n')
			ft_error("La map n'est pas entoure de murs\n", game);
		i++;
	}
}

void	check_map(t_game *game)
{
	if (!game->map[0])
		ft_error("Empty map", game);
	check_walls(game);
	check_mapchars(game);
	if (game->nbr_player > 1)
		ft_error("Il ne peut y avoir qu'un joueur\n", game);
	if (game->nbr_player < 1)
		ft_error("Il doit y avoir minimun un joueur\n", game);
	if (game->nbr_exit > 1)
		ft_error("Il ne peut y avoir qu'une sortie\n", game);
	if (game->nbr_exit < 1)
		ft_error("Il doit y avoir minimun une sortie\n", game);
}

