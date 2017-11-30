/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:23:12 by qtran             #+#    #+#             */
/*   Updated: 2017/11/30 11:18:06 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	ft_display_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
		{
			write(1, &map.m[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
/*
void	ft_display_tetri(t_tetri *t, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (t[i].tab[j])
		{
			printf("%s\n", t[i].tab[j]);	// printf
			j++;
		}
		j = 0;
		while (j < 4)
		{
			printf("%d : (%d %d)\n", i, t[i].coord.x[j], t[i].coord.y[j]); // printf
			j++;
		}
		i++;
	}
}*/
