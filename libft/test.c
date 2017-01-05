/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:48:51 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/22 14:39:22 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			main()
{
	char	*str;
	int		i;
	int		tab[10] = {100,101,102,103,104,105,106,107,108,109};


	i = 0;
	str = "abcdef";
	ft_putnbr(str[i]);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	i++;
	ft_putnbr(str[i]);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	str= str + 4;
	ft_putnbr(str[i]);
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	printf("%d\n", tab[9]);
	return (0);
}
