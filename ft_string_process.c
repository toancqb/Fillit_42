/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:50 by qtran             #+#    #+#             */
/*   Updated: 2017/12/04 23:35:03 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char    **ft_split_line(char *str, char c)
{
    char **tab;

    tab = ft_strsplit((char const *)str, c);
    return (tab);
}

char	**ft_init_tab(int x, int y)
{
	char	**str;
	int		i;
	int		j; //

	if (!(str = (char **)malloc(sizeof(char*) * (x + 1))) || !str)
		return (NULL);
	str[x] = NULL;
	i = 0;
	while (i < x)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (y + 1))) || !str[i])
			return (NULL);
    j = 0;//
    while (j < y)//
    {
      str[i][j] = '.';
      j++;
    }//
		str[i][y] = '\0';
		i++;
	}
	return (str);
}

void ft_del_tab(char **tab)
{
  int i;

  if (tab)
  {
    i = 0;
    while (tab[i])
    {
      free(tab[i]);
      i++;
    }
    *tab = NULL;
    free(tab);
  }
}

t_tetri	*ft_cpy_tab(char **tab)
{
	int		i;
	int		len;
	t_tetri	*t;
	int		k;

	len = ft_check_line(tab);
	if (!(t = (t_tetri *)malloc(sizeof(t_tetri) *
					(len + 1))) || !t)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		t[i++].tab = ft_init_tab(4, 4);
	}
	i = 0;
	k = 0;
	while (tab[i])
	{
		if (i != 0 && i % 4 == 0)
			k++;
		ft_strncpy(t[k].tab[i % 4], tab[i], 4);
		i++;
	}
	return (t);
}

static void	ft_assign_coord(t_tetri *t, char **tab)
{
	int i;
	int j;
	int flag;

	flag = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (flag == 0 && tab[i][j] == '#')
			{
				t->coord.x[0] = i;
				t->coord.y[0] = j;
				flag++;
			}
			else if (flag <= 3 && tab[i][j] == '#')
			{
				t->coord.x[flag] = i - t->coord.x[0];
				t->coord.y[flag++] = j - t->coord.y[0];
			}
			j++;
		}
		i++;
	}
}

t_tetri	*ft_cpy_coord(t_tetri *t, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
    t[i].flag = 0;
		ft_assign_coord(&t[i], t[i].tab);
		i++;
	}
	return (t);
}
