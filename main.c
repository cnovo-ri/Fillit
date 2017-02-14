/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:14:44 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/02/13 19:48:13 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

char		*check_read(char *argv);

int			main(int argc, char **argv)
{
	char	*tab;

	if (argc == 2)
	{
		tab = check_read(argv[1]);
		ft_putstr(tab);
	}
	else
		ft_putstr("usage: ./fillit target_file\n");
	return (0);
}
