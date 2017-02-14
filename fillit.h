/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:40:14 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/14 11:32:23 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct		s_struct
{
	int	x;
	int	y;
}					t_struct;

int			tetri_heigth(char **tab);
int			tetri_width(char **t);
void		free_map(char **map);
void		print_map(char **map);
char		**create_map(char **map, int map_size);
void		fill_map(char **map, int map_size);
int			check_tetri(char *str);
char		*check_read(char *argv);
char		**file_split(char *s);
char		***tetri_split(char **tab, int nb_tetri);
t_struct	*check_pos(char **tab);
char		***tetri_move(char ***cub, int nb_tetri);

#endif
