/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:37:10 by qtran             #+#    #+#             */
/*   Updated: 2017/12/20 15:45:04 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		ft_done(t_map *map, t_tetri *t, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (t[i].flag == 0)
			return (0);
		i++;
	}
	ft_display_map(*map);
	ft_del_map(&map);
	return (1);
}

int		ft_try_all_pos(t_map *map, int k, int *i, int *j)
{
	while (*i < map->size)
	{
		*j = 0;
		while (*j < map->size)
		{
			if (ft_add_tetri_to_map(map, k, *i, *j))
			{
				map->t[k].flag = 1;
				if (!ft_done(map, map->t, map->size_tetri))
				{
					ft_bt(map);
					ft_del_tetri_from_map(map, k, *i, *j);
					map->t[k].flag = 0;
				}
				else
					exit(EXIT_SUCCESS);
			}
			(*j)++;
		}
		(*i)++;
	}
	if (!(ft_add_tetri_to_map(map, k, *i, *j)))
		return (0);
	return (1);
}

int		ft_bt(t_map *map)
{
	int i;
	int j;
	int k;

	k = -1;
	i = 0;
	while (++k < map->size_tetri)
	{
		if (map->t[k].flag == 0)
		{
			if (ft_try_all_pos(map, k, &i, &j) == 0)
				break ;
		}
	}
	return (0);
}

void	ft_btracking(char *buf)
{
	int		len;
	int		m_map;
	t_map	*map;

	len = 0;
	m_map = 2;
	map = ft_init_map(NULL, 2);
	map->size = 2;
	map->t = ft_check_valid(buf, &len);
	map->size_tetri = len;
	while (m_map < 100)
	{
		if (ft_bt(map))
			break ;
		ft_del_tab(map->m);
		m_map++;
		map->size = m_map;
		map->m = ft_init_tab(m_map, m_map);
	}
	ft_del_map(&map);
}
