/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:38:31 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 16:05:21 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	**ft_split_line(char *str, char c)
{
	char **tab;

	tab = ft_strsplit((char const *)str, c);
	return (tab);
}

int		ft_check_line(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		i++;
	}
	if (i % 4 == 0)
		return (i / 4);
	else
		return (0);
}
