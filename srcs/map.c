/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:28 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 16:16:40 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


char    **parse_map(char const *argv)
{
    char    **map;
    int     fd;
    int     i;

    fd = open(argv, O_RDONLY);
    if (fd < 0) 
	{
        ft_printf("Error opening file\n");
        return (NULL);
    }
    map = (char **)malloc(sizeof(char *) * MAX_LINE);
    if (!map) 
	{
        ft_printf("Memory allocation failed\n");
        return (NULL);
    }
    i = 0;
    while ((map[i] = get_next_line(fd)) != NULL && i < MAX_LINE)
    {
        i++;
    }
    close(fd);
    return (map);
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
				ft_error("Caractere non accepte\n", game->map);
			else if (game->map[i][j] == 'P')
				game->nbr_player += 1;
			else if (game->map[i][j] == 'E')
				game->nbr_exit += 1;
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	check_mapchars(game);
	if (game->nbr_player > 1)
		ft_error("Il ne peut y avoir qu'un joueur", game->map);
	if (game->nbr_player < 1)
		ft_error("Il doit y avoir minimun un joueur", game->map);
	if (game->nbr_exit > 1)
		ft_error("Il ne peut y avoir qu'une sortie", game->map);
	if (game->nbr_exit < 1)
		ft_error("Il doit y avoir minimun une sortie", game->map);
}

