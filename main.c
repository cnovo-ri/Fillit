/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:14:44 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/18 18:17:48 by cnovo-ri         ###   ########.fr       */
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

	if (!(tmp = (char *)malloc(sizeof(char) * 546)))
		return (0);
	tmp = check_read(argv[1]);
	if ((nb_tetri = (ft_strlen(tmp) + 1) / 21) == 0 ||
			check_read(argv[1]) == NULL)
		return (0);
	if (argc != 2)
		ft_putstr("usage: ./fillit input_file\n");
	else
	{
		cub = tetri_move(tetri_split(file_split(check_read(argv[1])), nb_tetri),
				nb_tetri);
		map = solver(cub, nb_tetri);
		print_map(map);
	}
	return (0);
}
