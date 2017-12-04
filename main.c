/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:46:06 by qtran             #+#    #+#             */
/*   Updated: 2017/11/30 11:51:34 by qtran            ###   ########.fr       */
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

	if (!(map = ft_init_map(NULL, 2)) || !map)
		return (0);
	buf = ft_memalloc(BUF_SIZE);
	buf_tmp = ft_memalloc(21);
	if (argc != 2)
		write(1, "usage:", 6);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((n = read(fd, buf_tmp, 20)) > 0)
		{
			ft_strncat(buf, buf_tmp, n);
		}
		map->t = ft_check_valid(buf, &n);
		if (map->t == NULL)
			ft_error();
		map->size_tetri = n;
		printf("%d\n", ft_add_tetri_to_map(map, 2, 0, 0));
		printf("%d\n", ft_del_tetri_from_map(map, 2, 0, 0));
		ft_display_map(*map);
	}
	return (0);
}
