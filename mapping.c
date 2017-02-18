/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:49:30 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/18 15:58:11 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void		fill_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

char		**create_map(int map_size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		return (NULL);
	while (i < map_size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (map_size + 1))))
			return (NULL);
		map[i][map_size] = '\0';
		i++;
	}
	map[i] = NULL;
	fill_map(map, map_size);
	return (map);
}

void		print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

void		free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}
