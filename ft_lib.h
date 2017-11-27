/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:13:07 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 16:07:01 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIB_H
# define _FT_LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 2048
# define NB_TETRI 19
# define NB_BLOCK 17
# define X 4
# define Y 4

typedef struct	s_coord
{
	int x[3];
	int y[3];
}				t_coord;

typedef struct	s_tetri
{
	t_coord	coord;
	char	**tab;
}				t_tetri;

void	*ft_memalloc(size_t size);
void	ft_assign_value(char **s);
char	**ft_pattern_tetri(void);
char	**ft_init_tab(int x, int y);
char	**ft_split_line(char *str, char c);
char	**ft_strsplit(char const *str, char c); //
char	*ft_strncat(char *s1, const char *s2, size_t n); //
void	ft_putstr(char *s);
int		ft_check_line(char **tab);
#endif
