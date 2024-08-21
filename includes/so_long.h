/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:38:03 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/21 21:04:19 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

# define MAX_LINE 1000

typedef enum e_direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
}	t_direction;

typedef struct s_game
{
	char	**map;
	char	**cp_map;
	int		nbr_player;
	int		nbr_exit;
	char	*argv;
	size_t	nbr_row;
	size_t	row_len;
	int		nbr_collectible;
	int		player_pos_x;
	int		player_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		total_obj;
}	t_game;

void	parse_map(t_game *game);
void	free_game(t_game *game);
void	check_nbr_chars(t_game *game);
void	ft_error(char *error_msg, t_game *game);
void	init_game(t_game *game);
void	check_map(t_game *game);
void	parse_arg(t_game *game, char const *argv);
void	count_line_file(t_game *game);
void	null_terminate_rows(t_game *game);
void	check_rectangle_walls(t_game *game);
void	get_positions(t_game *game);
int		find_path(char **map, int y, int x, t_game *game);
void	cp_map(t_game *game);

#endif