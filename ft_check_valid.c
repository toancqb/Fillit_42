/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:38:31 by qtran             #+#    #+#             */
/*   Updated: 2017/11/30 11:51:29 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

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
		if (c_sh != 4 || c_p != 12)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_pattern(t_tetri *t, int len)
{
	t_coord *cmp_t;
	int		i;
	int		j;
	int		flag;
	int		k;

	cmp_t = ft_tetriminos();
	i = 0;
	flag = 0;
	while (i < len)
	{
		j = 0;
		while (j < NB_BLOCK)
		{
			flag = 0;
			k = 1;
			while (k < 4)
			{
				if (t[i].coord.x[k] == cmp_t[j].x[k] &&
						t[i].coord.y[k] == cmp_t[j].y[k])
					flag++;
				k++;
			}
			if (flag == 3)
				break ;
			j++;
		}
		if (flag != 3)
			return (0);
		i++;
	}
	return (1);
}

t_tetri	*ft_check_valid(char *buf, int *size_tetri)
{
	t_tetri *vn;
	char	**tab;

	tab = ft_split_line(buf, '\n');
	if (!(*size_tetri = ft_check_format(buf, tab)))
		return (NULL);
	vn = ft_cpy_tab(tab);
	vn = ft_cpy_coord(vn, *size_tetri);
	if (!ft_check_count(vn, *size_tetri)
				|| !ft_check_pattern(vn, *size_tetri))
		return (NULL);
	ft_del_tab(tab);
	return (vn);
}
