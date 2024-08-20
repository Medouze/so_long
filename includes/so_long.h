/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:38:03 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 12:56:54 by mlavergn         ###   ########.fr       */
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
}	t_game;

char    **parse_map(char const *argv);
void	free_map(char **map);

#endif