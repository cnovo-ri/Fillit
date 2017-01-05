/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:14:01 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/01/05 14:34:28 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			call_check(int connect, int i, char *str)
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

int			check_tetri(char *str)
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
			return (0);
		if (str[i] == '#')
		{
			connect = call_check(connect, i, str);
			diez++;
		}
		i++;
	}
	if (diez == 4 && i == 21)
		return (connect);
	return (0);
}
