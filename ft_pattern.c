/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:08:23 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 11:35:36 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"



void	ft_assign_value(static char **s)
{
	ft_strcpy(s[0], "##..#...#");	
}

char	**ft_pattern_tetri(void)
{
	static char	**s;
	int			i;

	if (!(s = (char**)malloc(sizeof(char *) * (NB_BLOCK + 1))) || !s)
		return (0);
	s[NB_TETRI] = NULL;
	i = 0;
	while (i < NB_TETRI)
	{
		if (!(s[i] = ft_memmalloc(NB_TETRI)) || !s)
			return (0);
		i++;
	}
	ft_assign_value(s);
	return ((char**)s);
}
