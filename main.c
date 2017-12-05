/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:46:06 by qtran             #+#    #+#             */
/*   Updated: 2017/12/04 23:32:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		main(int argc, char *argv[])
{
	char	*buf;
	char	*buf_tmp;
	int		fd;
	int		n;
	t_map	*map;

	if (!(map = ft_init_map(NULL, 4)) || !map)
		return (0);
	buf = ft_memalloc(BUF_SIZE);
	buf_tmp = ft_memalloc(21);
	if (argc != 2)
		write(1, "usage: ./fillit source file\n", 27);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((n = read(fd, buf_tmp, 20)) > 0)
		{
			ft_strncat(buf, buf_tmp, n);
		}
		map->t = ft_check_valid(buf, &n);
		if (map->t == NULL)
		{
			ft_error();
			ft_del_map(&map);
			exit(0);
		}
		//map->size_tetri = n;
		ft_del_map(&map);
		//ft_done(map->t, map->size_tetri);
		//printf("\n%d\n", map->size_tetri);
		//ft_bt(map, 0);
		ft_btracking(buf);
	}
	return (0);
}
