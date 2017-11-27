/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:46:06 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 16:04:33 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"
#include <stdio.h>

int		main(int argc, char *argv[])
{
	char *buf, *buf_tmp;
	int fd;
	int n;
	char **tab;

	buf = ft_memalloc(BUF_SIZE);
	buf_tmp = ft_memalloc(10);
	if (argc != 2)
		write(1, "usage:", 7);
	else
	{
		fd = open(argv[1], O_RDONLY);
		while ((n = read(fd, buf_tmp, sizeof(buf_tmp))) > 0)
		{
			ft_strncat(buf, buf_tmp, n);
		}
		tab = ft_split_line(buf, '\n');
		printf("%d \n", ft_check_line(tab));	
	}
	return (0);
}
