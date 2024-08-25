/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:42:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 21:01:32 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_arg(t_game *game, char const *argv)
{
	char	*str;
	char	*path;

	path = ft_strchr(argv, '/');
	if (!path || ft_strlen(path) == 5)
		ft_error("Wrong map extension\n", game);
	str = ft_strchr(argv, '.');
	if (!str || ft_strncmp(str, ".ber", 5) != 0)
		ft_error("Wrong map extension\n", game);
	game->argv = malloc(ft_strlen(argv) + 1);
	if (!game->argv)
		ft_error("Allocation failed\n", game);
	ft_strlcpy(game->argv, argv, ft_strlen(argv) + 1);
}

void	get_nbr_row(t_game *game)
{
	char	*str;
	int		fd;

	fd = open(game->argv, O_RDONLY);
	if (fd < 0)
		ft_error("Couldnt open file\n", game);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		game->nbr_row++;
		free(str);
	}
	close(fd);
}

void	parse_map(t_game *game)
{
	int		fd;
	size_t	i;

	fd = open(game->argv, O_RDONLY);
	if (fd < 0)
		ft_error("Can't open file\n", game);
	game->map = malloc(sizeof(char *) * (game->nbr_row + 1));
	if (!game->map)
		ft_error("Allocation failed\n", game);
	game->map[game->nbr_row] = NULL;
	i = 0;
	while (i < game->nbr_row)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	null_terminate_rows(game);
}

void	init_game(t_game *game)
{
	get_nbr_row(game);
	parse_map(game);
	if (!game->map[0])
		ft_error("Map is empty\n", game);
	game->row_len = ft_strlen(game->map[0]);
	check_map(game);
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
		ft_error("Allocation failed\n", game);
	game->window.mlx_window = mlx_new_window(game->window.mlx,
			game->row_len * 32, game->nbr_row * 32, "My game");
	if (!game->window.mlx_window)
		ft_error("Allocation failed\n", game);
	init_image(game);
}
