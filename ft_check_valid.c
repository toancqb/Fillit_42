/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:38:31 by qtran             #+#    #+#             */
/*   Updated: 2017/11/28 17:19:51 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	**ft_split_line(char *str, char c)
{
	char **tab;

	tab = ft_strsplit((char const *)str, c);
	return (tab);
}

int		ft_check_buf(char *buf)
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

int		ft_check_line(char **tab)
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

int		ft_check_format(char *buf, char **tab)
{
	if (!(ft_check_buf(buf)))
		return (0);
	return (ft_check_line(tab));
}

static void	ft_count_pattern(char **tab, int *sh, int *p)
{
	int i;
	int j;

	*sh = 0;
	*p = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				(*sh)++;
			if (tab[i][j] == '.')
				(*p)++;
			j++;
		}
		i++;
	}
}

int		ft_check_count(t_tetri *t, int len)
{
	int i;
	int j;
	int c_sh;
	int c_p;

	i = 0;
	while (i < len)
	{
		ft_count_pattern(t[i].tab, &c_sh, &c_p);
		printf("%d  %d\n", c_sh, c_p);
		if (c_sh != 4 || c_p != 12)
			return (0);
		i++;
	}
	return (1);
}
