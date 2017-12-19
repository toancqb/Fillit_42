/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:12:06 by qtran             #+#    #+#             */
/*   Updated: 2017/12/19 17:19:29 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static int		ft_check_last_buf(char *buf)
{
	int len;

	len = ft_strlen(buf);
	if (buf[len - 1] == '\n' && buf[len - 2] == '\n')
		return (0);
	return (1);
}

int				ft_check_buf(char *buf)
{
	int i[3];

	i[2] = 0;
	i[1] = 0;
	i[0] = 4;
	while (i[0] < ft_strlen(buf) || buf[i[1]] != '\0')
	{
		if (i[0] < ft_strlen(buf) && i[1] == i[0])
		{
			if (buf[i[1]] != '\n')
				return (0);
			i[2]++;
			if (i[2] == 4)
			{
				i[2] = -1;
				i[0]++;
			}
			else
				i[0] += 5;
		}
		else if (buf[i[1]] == '\n')
			return (0);
		i[1]++;
	}
	return (1);
}

int				ft_check_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		i++;
	}
	if (i % 4 == 0)
		return (i / 4);
	else
		return (0);
}

int				ft_check_format(char *buf, char **tab)
{
	if (!(ft_check_last_buf(buf)) || !(ft_check_buf(buf)))
		return (0);
	return (ft_check_line(tab));
}
