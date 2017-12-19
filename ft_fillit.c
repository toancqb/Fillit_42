/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:37:10 by qtran             #+#    #+#             */
/*   Updated: 2017/12/19 17:07:46 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		ft_done(t_tetri *t, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (t[i].flag == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_bt(t_map *map, int k_tetri)
{
	int i;
	int j;
	int k;
	int p;

	k = 0;
	while (k < map->size_tetri)
	{
		if (map->t[k].flag == 0)
		{
			i = 0;
			while (i < map->size)
			{
				j = 0;
				while (j < map->size)
				{
					p = ft_add_tetri_to_map(map, k, i, j);
					if (p)
					{
						map->t[k].flag = 1;
						if (ft_done(map->t, map->size_tetri))
						{
							ft_display_map(*map);
							ft_del_map(&map);
							exit(1);
						}
						else
						{
							ft_bt(map, k_tetri + 1);
							ft_del_tetri_from_map(map, k, i, j);
							map->t[k].flag = 0;
						}
					}
					j++;
				}
				if (p)
					break ;
				i++;
			}
			if (!p)
				return (0);
		}
		k++;
	}
	return (0);
}
/*
   int ft_bt(t_map *map, int k_tetri)
   {
   int i;
   int j;
   int k;

   k = 0;
   while (k < map->size_tetri)
   {
   if (!map->t[k].flag)
   {

   }
   k++;
   }
   }*/

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
		if (ft_bt(map, 0))
			break ;
		ft_del_tab(map->m);
		m_map++;
		map->size = m_map;
		map->m = ft_init_tab(m_map, m_map);
	}
	ft_del_map(&map);
}
