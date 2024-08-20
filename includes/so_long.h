/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:38:03 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 16:17:41 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

# define MAX_LINE 1000

typedef struct s_game
{
	char	**map;
	int		nbr_player;
	int		nbr_exit;
}	t_game;

char    **parse_map(char const *argv);
void	free_map(char **map);
void	check_mapchars(t_game *game);
void	ft_error(char *error_msg, char **map);
void	init_game(t_game *game, char const *argv);
void	check_map(t_game *game);

#endif