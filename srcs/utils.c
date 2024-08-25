/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:53:58 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/25 02:43:03 by mlavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(t_game *game)
{
	int		i;
	char	**cp_map;

	cp_map = malloc(sizeof(char *) * (game->nbr_row + 1));
	if (!cp_map)
		ft_error("Allocation error\n", game);
	i = -1;
	while (game->map[++i])
	{
		cp_map[i] = ft_strdup(game->map[i]);
		if (!cp_map[i])
		{
			free_map(cp_map);
			ft_error("Allocation failed\n", game);
		}
	}
	cp_map[game->nbr_row] = NULL;
	return (cp_map);
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
