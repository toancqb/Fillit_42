/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:46:06 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 12:07:41 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		main(int argc, char *argv[])
{
	int i;
	int j;
	char *buf;
	int fd;
	int n;

	buf = ft_memalloc(BUF_SIZE);
	if (argc != 2)
		write(1, "usage:", 7);
	else
	{
		fd = open(argv[1], O_RDONLY);
		i = 0;
		while ((n = read(fd, buf, BUF_SIZE - 1)) > 0)
		{
			while (n >= 0)
		}	
	}
	return (0);
}
