/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:23:12 by qtran             #+#    #+#             */
/*   Updated: 2017/12/04 23:31:23 by qtran            ###   ########.fr       */
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
