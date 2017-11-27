/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:08:23 by qtran             #+#    #+#             */
/*   Updated: 2017/11/23 14:17:52 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	vocabulary_tetri(void)
{
	static char **s;
	int i;

	if (!(s = (char**)malloc(sizeof(char *) * (NB_TETRI + 1))) || !s)
		return (0);
	s[NB_TETRI] = NULL;
	i = 0;
	while (i < NB_TETRI)
	{
		if (!(s[i] = ft_memmalloc(NB_BLOCK)) || !s)
			return (0);
		ft_strcpy(s[i], "");
		i++;
	}

}
