/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:37:28 by mlavergn          #+#    #+#             */
/*   Updated: 2024/08/20 12:36:27 by mlavergn         ###   ########.fr       */
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

