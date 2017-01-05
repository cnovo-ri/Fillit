/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:09:08 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/01/05 18:48:40 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>


#define BUF_SIZE 21

int			check_tetri(char *str);

int			open_read(int fd)
{
	int		ret;
	char	buf[BUF_SIZE];
	int		i;
	char	*tab;

	i = 0;
	tab = "";
	while ((ret = read(fd, buf, 21)))
	{
		if ((check_tetri(buf) == 6 || check_tetri(buf) == 8) && (i < 26))
		{
			buf[ret] = '\0';
			tab = ft_strjoin(tab, buf);
			i++;
		}
		else
		{
			ft_putstr("\033[0;31m-------->ERROR<--------\n     Wrong way boy\n");
			return (1);
		}
	}
	ft_putstr(tab);
	return (0);
}
