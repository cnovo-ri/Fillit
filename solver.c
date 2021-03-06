/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:16:44 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/18 18:15:08 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			solve_map(char ***cub, char **map, int map_size, int tetri_num)
{
	t_struct	pos;

	pos.x = 0;
	if (*cub == NULL)
		return (1);
	while (pos.x < map_size - tetri_heigth(*cub) + 1)
	{
		pos.y = 0;
		while (pos.y < map_size - tetri_width(*cub) + 1)
		{
			if (place_tetri(*cub, map, pos, tetri_num))
			{
				if (solve_map((cub + 1), map, map_size, (tetri_num + 1)))
					return (1);
				else
					set_tetri(*cub, map, pos, '.');
			}
			pos.y++;
		}
		pos.x++;
	}
	return (0);
}

int			place_tetri(char **tetri, char **map, t_struct pos, int tetri_num)
{
	int i;
	int j;

	i = 0;
	while (i < tetri_heigth(tetri))
	{
		j = 0;
		while (j < tetri_width(tetri))
		{
			if (tetri[i][j] == '#' && map[pos.x + i][pos.y + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_tetri(tetri, map, pos, (char)(tetri_num + 65));
	return (1);
}

void		set_tetri(char **tetri, char **map, t_struct pos, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri_heigth(tetri))
	{
		j = 0;
		while (j < tetri_width(tetri))
		{
			if (tetri[i][j] == '#')
				map[pos.x + i][pos.y + j] = c;
			j++;
		}
		i++;
	}
}

char		**solver(char ***cub, int nb_tetri)
{
	char	**map;
	int		map_size;
	int		i;

	i = 0;
	map_size = ft_sqrt((nb_tetri) * 4);
	map = create_map(map_size);
	while (!(solve_map(cub, map, map_size, i)))
	{
		free_map(map);
		map_size++;
		map = create_map(map_size);
	}
	return (map);
}
