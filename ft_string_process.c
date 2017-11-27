/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:50 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 11:44:44 by qtran            ###   ########.fr       */
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
