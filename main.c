/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_Tetriminos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:22:01 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/01/05 18:48:48 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

#define BUF_SIZE 546

int			open_read(int fd);

int			main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		ft_putstr("usage: ./fillit target_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		open_read(fd);
	}
	return (0);
}
