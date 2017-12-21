/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:08:23 by qtran             #+#    #+#             */
/*   Updated: 2017/12/21 12:06:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

t_coord	*ft_tetriminos(void)
{
	static t_coord cmp_tetri[NB_BLOCK];

	cmp_tetri[0] = (t_coord){{0, 0, 1, 2}, {0, 1, 0, 0}};
	cmp_tetri[1] = (t_coord){{0, 0, 1, 2}, {0, 1, 1, 1}};
	cmp_tetri[2] = (t_coord){{0, 1, 2, 2}, {0, 0, 0, 1}};
	cmp_tetri[3] = (t_coord){{0, 1, 2, 2}, {1, 0, -1, 0}};
	cmp_tetri[4] = (t_coord){{0, 1, 1, 1}, {0, 0, 1, 2}};
	cmp_tetri[5] = (t_coord){{0, 1, 1, 1}, {2, -2, -1, 0}};
	cmp_tetri[6] = (t_coord){{0, 0, 0, 0}, {0, 1, 2, 3}};
	cmp_tetri[7] = (t_coord){{0, 1, 2, 3}, {0, 0, 0, 0}};
	cmp_tetri[8] = (t_coord){{0, 0, 1, 1}, {0, 1, 0, 1}};
	cmp_tetri[9] = (t_coord){{0, 0, 1, 1}, {0, 1, 1, 2}};
	cmp_tetri[10] = (t_coord){{0, 0, 1, 1}, {1, 1, -1, 0}};
	cmp_tetri[11] = (t_coord){{0, 1, 1, 2}, {1, -1, 0, -1}};
	cmp_tetri[12] = (t_coord){{0, 1, 1, 2}, {0, 0, 1, 1}};
	cmp_tetri[13] = (t_coord){{0, 1, 1, 1}, {1, -1, 0, 1}};
	cmp_tetri[14] = (t_coord){{0, 0, 0, 1}, {0, 1, 2, 1}};
	cmp_tetri[15] = (t_coord){{0, 1, 1, 2}, {0, 0, 1, 0}};
	cmp_tetri[16] = (t_coord){{0, 1, 1, 2}, {1, -1, 0, 0}};
	cmp_tetri[17] = (t_coord){{0, 0, 0, 1}, {0, 1, 2, 2}};
	cmp_tetri[18] = (t_coord){{0, 0, 0, 1}, {0, 1, 2, 0}};
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
	if (map)
	{
		free((*map)->t);
		ft_del_tab((*map)->m);
		*map = NULL;
	}
}

int		ft_add_tetri_to_map(t_map *map, int index, int x, int y)
{
	int i;

	if (x >= map->size || y >= map->size || index >= map->size_tetri
			|| map->m[x][y] != '.')
		return (0);
	i = 1;
	while (i < 4 && x + map->t[index].coord.x[i] < map->size
			&& y + map->t[index].coord.y[i] < map->size)
	{
		if (map->m[x + map->t[index].coord.x[i]]
				[y + map->t[index].coord.y[i]] != '.')
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	map->m[x][y] = 'A' + index;
	i = 1;
	while (i < 4)
	{
		map->m[x + map->t[index].coord.x[i]]
			[y + map->t[index].coord.y[i]] = 'A' + index;
		i++;
	}
	return (1);
}

int		ft_del_tetri_from_map(t_map *map, int index, int x, int y)
{
	int i;

	if (x >= map->size || y >= map->size || index >= map->size_tetri
			|| map->m[x][y] == '.')
		return (0);
	i = 1;
	while (i < 4 && x + map->t[index].coord.x[i] < map->size
			&& y + map->t[index].coord.y[i] < map->size)
	{
		if (map->m[x + map->t[index].coord.x[i]]
				[y + map->t[index].coord.y[i]] == '.')
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	map->m[x][y] = '.';
	i = 1;
	while (i < 4)
	{
		map->m[x + map->t[index].coord.x[i]]
			[y + map->t[index].coord.y[i]] = '.';
		i++;
	}
	return (1);
}
