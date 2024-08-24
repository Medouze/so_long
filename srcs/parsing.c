/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:42:54 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 00:16:20 by mlavergn         ###   ########.fr       */
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
	game->argv = malloc(strlen(argv) + 1);
	if (strcmp(argv - 5, "/") == 0)
	if (!game->argv)
		ft_error("Allocation failed\n", game);
	ft_strlcpy(game->argv, argv, strlen(argv) + 1);
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

void	cp_map(t_game *game)
{
	int		i;
	int		j;

	game->cp_map = malloc(sizeof(char *) * (game->nbr_row + 1));
	if (!game->cp_map)
		return ;
	game->cp_map[game->nbr_row] = NULL;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		game->cp_map[i] = malloc(sizeof(char) * (ft_strlen(game->map[i]) + 1));
		if (!game->cp_map[i])
			return ;
		while (game->map[i][++j])
			game->cp_map[i][j] = game->map[i][j];
		game->cp_map[i][j] = '\0';
	}
}


void	ft_error(char *error_msg, t_game *game)
{
	ft_printf("Error\n");
	ft_printf("%s", error_msg);
	free_game(game);
	exit(EXIT_FAILURE);
}
