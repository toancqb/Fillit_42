/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:38:31 by qtran             #+#    #+#             */
/*   Updated: 2017/12/19 17:14:40 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static void	ft_count_pattern(char **tab, int *sh, int *p)
{
	int i;
	int j;

	*sh = 0;
	*p = 0;
	i = 0;
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
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

int			ft_check_count(t_tetri *t, int len)
{
	int i;
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

int			ft_check_pattern(t_tetri *t, int len, t_coord *cmp_t)
{
	int		i[4];

	i[0] = 0;
	while (i[0] < len)
	{
		i[1] = 0;
		while (i[1] < NB_BLOCK)
		{
			i[2] = 0;
			i[3] = 1;
			while (i[3] < 4)
			{
				if (t[i[0]].coord.x[i[3]] == cmp_t[i[1]].x[i[3]] &&
						t[i[0]].coord.y[i[3]] == cmp_t[i[1]].y[i[3]])
					i[2]++;
				i[3]++;
			}
			if (i[1]++ && i[2] == 3)
				break ;
		}
		if (i[2] != 3)
			return (0);
		i[0]++;
	}
	return (1);
}

t_tetri		*ft_check_valid(char *buf, int *size_tetri)
{
	t_tetri *vn;
	char	**tab;

	tab = ft_split_line(buf, '\n');
	if (!(*size_tetri = ft_check_format(buf, tab)))
		return (NULL);
	vn = ft_cpy_tab(tab);
	vn = ft_cpy_coord(vn, *size_tetri);
	if (!ft_check_count(vn, *size_tetri)
			|| !ft_check_pattern(vn, *size_tetri, ft_tetriminos()))
		return (NULL);
	ft_del_tab(tab);
	return (vn);
}
