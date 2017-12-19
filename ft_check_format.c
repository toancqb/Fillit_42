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
	int i;
	int j;
	int	c;

	c = 0;
	j = 0;
	i = 4;
	while (i < ft_strlen(buf) || buf[j] != '\0')
	{
		if (i < ft_strlen(buf) && j == i)
		{
			if (buf[j] != '\n')
				return (0);
			c++;
			if (c == 4)
			{
				c = -1;
				i++;
			}
			else
				i += 5;
		}
		else if (buf[j] == '\n')
			return (0);
		j++;
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
