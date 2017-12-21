/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:18:15 by qtran             #+#    #+#             */
/*   Updated: 2017/11/15 16:27:20 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_check_sign(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

static int		min_value(const char *s)
{
	if (s[0] == '-' && s[1] == '2' && s[2] == '1' && s[3] == '4'
			&& s[4] == '7' && s[5] == '4' && s[6] == '8' && s[7] == '3'
			&& s[8] == '6' && s[9] == '4' && s[10] == '8')
		return (-2147483648);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	if (min_value(str) != 0)
		return (min_value(str));
	ft_check_sign(str, &i, &sign);
	if (!ft_isdigit(str[i]))
		return (0);
	res = (int)str[i++] - '0';
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = res * 10 + (int)str[i++] - '0';
	}
	return (res * sign);
}
