/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:50 by qtran             #+#    #+#             */
/*   Updated: 2017/11/28 14:58:52 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	**ft_init_tab(int x, int y)
{
	char	**str;
	int		i;

	if (!(str = (char **)malloc(sizeof(char*) * (x + 1))) || !str)
		return (NULL);
	str[x] = NULL;
	i = 0;
	while (i < x)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (y + 1))) || !str[i])
			return (NULL);
		str[i][y] = '\0';
		i++;
	}
	return (str);
}
/*
t_tetri	*ft_cpy_to_tetri(char **tab)
{
	int		i;
	int		k;
	t_tetri	*t;
	int		j;

	if (!(t = (t_tetri *)malloc(sizeof(t_tetri) *
					(ft_check_line(tab) + 1))) || !t)
		return (NULL);
	i = 0;
	k = 0;
	while (tab[i])
	{
		if (i % 4 == 0)
		{
			t[k].tab[j] = 0;
			t[k++].tab = ft_init_tab(5, 4);
			j = 0;
		}
		else
		{
			ft_strncpy(t[k].tab[j], tab[i], 4);
			i++;
			j++;
		}
	}
	return (t);
}*/
