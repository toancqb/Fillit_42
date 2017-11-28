/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:23:12 by qtran             #+#    #+#             */
/*   Updated: 2017/11/28 19:04:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	ft_error(void)
{
	write(1, "error\n", 7);
	exit(0);
}

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
}

/*
void	ft_display_tetri(t_tetri t)
{
	int i;

	i = 0;
	while (t.tab[i])
	{
		ft_putstr(t.tab[i]);
		write(1, "\n", 2);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		//ft_putnbr(t.coord.x[i]);
		printf("%d : (%d  %d)\n", i, t.coord.x[i], t.coord.y[i]);
		i++;
	}
}*/
