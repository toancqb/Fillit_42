/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:08:23 by qtran             #+#    #+#             */
/*   Updated: 2017/11/30 11:51:24 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

t_coord *ft_tetriminos(void)
{
	static t_coord cmp_tetri[NB_BLOCK]
    =   {
            {{0, 0, 1, 2}, {0, 1, 0, 0}}, {{0, 0, 1, 2}, {0, 1, 1, 1}},
            {{0, 1, 2, 2}, {0, 0, 0, 1}}, {{0, 1, 2, 2}, {1, 0, -1, 0}},
            {{0, 1, 1, 1}, {0, 0, 1, 2}}, {{0, 1, 1, 1}, {2, -2, -1, 0}},
            {{0, 0, 0, 0}, {0, 1, 2, 3}}, {{0, 1, 2, 3}, {0, 0, 0, 0}},
            {{0, 0, 1, 1}, {0, 1, 0, 1}}, {{0, 0, 1, 1}, {0, 1, 1, 2}},
            {{0, 0, 1, 1}, {1, 1, -1, 0}}, {{0, 1, 1, 2}, {1, -1, 0, -1}},
            {{0, 1, 1, 2}, {0, 0, 1, 1}}, {{0, 1, 1, 1}, {1, -1, 0, 1}},
            {{0, 0, 0, 1}, {0, 1, 2, 1}}, {{0, 1, 1, 2}, {0, 0, 1, 0}},
            {{0, 1, 1, 2}, {1, -1, 0, 0}}
        };
    return (cmp_tetri);
}

t_map	*ft_init_map(t_tetri *t, int size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))) || !map)
		return (NULL);
	map->t = t;
	map->size = size;
	if (!(map->m = ft_init_tab(size, size)) || !map->m)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->m[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_del_map(t_map **map)
{
	int i;

	if (map)
	{
		free((*map)->t);
		ft_del_tab((*map)->m);
		/*i = 0;
		while (i < (*map)->size)
		{
			free((*map)->m[i]);
			i++;
		}
		free((*map)->m);*/
		*map = NULL;
	}
}
/*
int		ft_add_tetri_to_map(t_map *map, int index, int x, int y)
{
	int i;
	int j;

	if (x < map->size || y < map->size || )
}*/
