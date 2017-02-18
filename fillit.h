/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:40:14 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/18 17:37:07 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct	s_struct
{
	int	x;
	int	y;
}				t_struct;

char			**solver(char ***cub, int nb_tetri);
int				place_tetri(char **tetri, char **map, t_struct pos,
					int tetri_num);
void			set_tetri(char **tetri, char **map, t_struct pos, char c);
int				solve_map(char ***cub, char **map, int map_size, int tetri_num);
int				tetri_heigth(char **tab);
int				tetri_width(char **t);
void			free_map(char **map);
void			print_map(char **map);
char			**create_map(int map_size);
void			fill_map(char **map, int map_size);
int				check_tetri(char *str);
char			*check_read(char *argv);
char			**file_split(char *s);
char			***tetri_split(char **tab, int nb_tetri);
t_struct		*check_pos(char **tab);
char			***tetri_move(char ***cub, int nb_tetri);

#endif
