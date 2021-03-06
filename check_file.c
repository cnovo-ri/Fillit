/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:52:05 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/20 19:58:27 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		call_check(int connect, int i, char *str)
{
	if (i - 1 >= 0 && str[i - 1] == '#')
		connect++;
	if (i + 1 < 20 && str[i + 1] == '#')
		connect++;
	if (i - 5 >= 0 && str[i - 5] == '#')
		connect++;
	if (i + 5 < 20 && str[i + 5] == '#')
		connect++;
	return (connect);
}

int				check_tetri(char *str)
{
	int i;
	int connect;
	int	diez;

	i = 0;
	connect = 0;
	diez = 0;
	while (str[i] != '\0' && (str[i] == '.' || str[i] == '#' || str[i] == '\n'))
	{
		if (i != 4 && i != 9 && i != 14 && i != 19 && i != 20 && str[i] == '\n')
			return (1);
		if (str[i] == '#')
		{
			connect = call_check(connect, i, str);
			diez++;
		}
		i++;
	}
	if ((diez == 4 && i == 21) || (diez == 4 && i == 20))
		return (connect);
	return (0);
}

static char		*check_return(char *buf, char *tab, int fd)
{
	int ret;
	int i;

	i = 0;
	while ((ret = read(fd, buf, 21)))
	{
		if ((check_tetri(buf) == 6 || check_tetri(buf) == 8) && (i < 26)
				&& (ret >= 20))
		{
			buf[ret] = '\0';
			tab = ft_strjoin(tab, buf);
			i++;
		}
		else
		{
			ft_putstr("error\n");
			return (NULL);
		}
	}
	return (tab);
}

char			*check_read(char *argv)
{
	int		fd;
	char	*buf;
	char	*tmp;
	char	*tab;
	int		ret;

	tab = "";
	if (!(buf = (char *)malloc(sizeof(char) * 546)))
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (!(tab = check_return(buf, tab, fd)))
		return (NULL);
	close(fd);
	free(buf);
	return (tab);
}

char			*global_read(char *argv)
{
	int		fd;
	int		ret;
	int		ret_open;
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * 546)))
		return (NULL);
	fd = open(argv, O_RDONLY);
	ret = read(fd, tmp, 546);
	ret_open = fd;
	close(fd);
	if ((ret_open > -1 && ret == -1) || (ret + 1) % 21 != 0)
	{
		free(tmp);
		ft_putstr("error\n");
		return (0);
	}
	return (tmp);
}
