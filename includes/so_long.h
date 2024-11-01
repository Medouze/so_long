/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:38:03 by mlavergn          #+#    #+#             */
/*   Updated: 2024/11/01 22:03:51 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_img
{
	char	*wall;
	char	*hero;
	char	*coin;
	char	*back;
	char	*exit;
	int		width;
	int		height;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*mlx_window;
}	t_window;

typedef struct s_game
{
	char		**map;
	int			nbr_player;
	int			nbr_exit;
	char		*argv;
	size_t		nbr_row;
	size_t		row_len;
	int			nbr_collectible;
	int			total_obj;
	int			player_pos_x;
	int			player_pos_y;
	int			exit_pos_x;
	int			exit_pos_y;
	int			total_play;
	t_img		img;
	t_window	window;
}	t_game;

/* Parsing functions */
void	parse_map(t_game *game);
void	get_nbr_row(t_game *game);
void	init_game(t_game *game);
void	parse_arg(t_game *game, char const *argv);
/* Utils */
void	null_terminate_rows(t_game *game);
char	*ft_itoa(int n);
char	**copy_map(t_game *game);
/* Check for maps and checks for path*/
void	check_map(t_game *game);
void	check_map_format(t_game *game);
void	check_nbr_obj(char c, int y, int x, t_game *game);
int		find_path(int y, int x, t_game *game);
int		path_collect(char **map, int y, int x, int *collectibles);
int		path_exit(char **map, int y, int x);
/* Mlx, keyboard -> screen */
int		close_window(t_game *game);
int		parse_key(int keycode, t_game *game);
/* Mlx, print -> screen */
void	draw_text(t_game *game);
void	init_image(t_game *game);
void	set_img_map(t_game *game, int i, int j);
void	ft_put_img_map(t_game *game);
/* Mlx, character movements */
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
/* Utils free/error */
void	free_map(char **map);
void	free_game(t_game *game);
void	ft_error(char *error_msg, t_game *game);

#endif