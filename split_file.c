/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:52:23 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/02 20:07:03 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

char			**file_split(char *s)
{
	int				i;
	int				nb_tetri;
	char			**tab;
	unsigned int	start;
	size_t			len;

	i = 0;
	nb_tetri = (ft_strlen(s) + 1) / 21;
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_tetri + 1))))
		return (NULL);
	start = 0;
	len = 20;
	while (i < nb_tetri)
	{
		tab[i] = ft_strsub((const char *)s, start, len);
		start = start + 21;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			***tetri_split(char **tab, int nb_tetri)
{
	char	***cub;
	int		i;

	i = 0;
	if (!(cub = (char ***)malloc(sizeof(char **) * (nb_tetri + 1))))
		return (NULL);
	while (i < nb_tetri)
	{
		cub[i] = ft_strsplit((const char *)tab[i], '\n');
		i++;
	}
	cub[i] = NULL;
	return (cub);
}

t_struct		*check_pos(char **tab)
{
	int			i;
	int			j;
	t_struct	*pos;

	if (!(pos = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	i = 0;
	pos->x = 4;
	pos->y = 4;
	while (i < 4)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#' && i < pos->x)
				pos->x = i;
			if (tab[i][j] == '#' && j < pos->y)
				pos->y = j;
			j++;
		}
		i++;
	}
	return (pos);
}

static char		***real_move(char ***cub, t_struct *tmp, int nb_tetri, int i)
{
	int	j;
	int	k;

	while (i < nb_tetri)
	{
		tmp = check_pos(cub[i]);
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (cub[i][j][k] == '#' && (tmp->x != 0 || tmp->y != 0))
				{
					cub[i][j - tmp->x][k - tmp->y] = '#';
					cub[i][j][k] = '.';
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (cub);
}

char			***tetri_move(char ***cub, int nb_tetri)
{
	int			i;
	t_struct	*tmp;

	if (!(tmp = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	i = 0;
	real_move(cub, tmp, nb_tetri, i);
	free(tmp);
	return (cub);
}
