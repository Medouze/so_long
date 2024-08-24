/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:53:58 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 00:17:21 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game)
{
	int	i;

	if (game == NULL)
		return ;
	if (game->map)
	{
		i = -1;
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	if (game->cp_map)
	{
		i = -1;
		while (game->cp_map[++i])
			free(game->cp_map[i]);
		free(game->cp_map);
	}
	if (game->argv)
		free(game->argv);
}

void	init_game(t_game *game)
{
	get_nbr_row(game);
	parse_map(game);
	if (!game->map[0])
		ft_error("Map is empty\n", game);
	cp_map(game);
	game->row_len = ft_strlen(game->map[0]);
	game->window.mlx = mlx_init();
	if (!game->window.mlx)
		ft_error("Allocation failed\n", game);
	game->window.mlx_window = mlx_new_window(game->window.mlx,
			game->row_len * 32, game->nbr_row * 32, "My game");
	if (!game->window.mlx_window)
		ft_error("Allocation failed\n", game);
	init_image(game);
}

void	null_terminate_rows(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '\n')
			{
				game->map[i][j] = '\0';
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	nbr_len(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nbr;

	nbr = n;
	size = nbr_len(nbr);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
