/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:46:06 by qtran             #+#    #+#             */
/*   Updated: 2017/11/29 14:16:22 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char *buf, *buf_tmp;
	int fd;
	int n;
	int i;
	char **tab;
	int len;
	t_tetri *vn;
	//char test[] = "1111\n2222\n3333\n4444";

	buf = ft_memalloc(BUF_SIZE);
	buf_tmp = ft_memalloc(21);
	buf_tmp[20] = '\0';
	if (argc != 2)
		write(1, "usage:", 7);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((n = read(fd, buf_tmp, 20)) > 0)
		{
			ft_strncat(buf, buf_tmp, n);
		}
		printf("%d\n", ft_check_valid(buf));
	}
	return (0);
}
