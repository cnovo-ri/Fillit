/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:14:44 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/02 12:05:31 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int			main(int argc, char **argv)
{
	char	***cub;
	char	**map;
	char	*tmp;
	int		nb_tetri;

	if (!(tmp = global_read(argv[1])))
		return (0);
	else if (argc == 2)
	{
		if ((nb_tetri = (ft_strlen(tmp) + 1) / 21) == 0)
			return (0);
	}
	else
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	free(tmp);
	cub = tetri_move(tetri_split(file_split(check_read(argv[1])), nb_tetri),
			nb_tetri);
	map = solver(cub, nb_tetri);
	print_map(map);
	return (0);
}
