/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:13:07 by qtran             #+#    #+#             */
/*   Updated: 2017/11/29 14:23:42 by qtran            ###   ########.fr       */
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

# include <stdio.h> // TEST

typedef struct	s_coord
{
	int x[4];
	int y[4];
}				t_coord;

typedef struct	s_tetri
{
	t_coord	coord;
	char	**tab;
}				t_tetri;

void	ft_assign_value(char **s);
char	**ft_pattern_tetri(void);
char	**ft_init_tab(int x, int y);
char	**ft_split_line(char *str, char c);
void	ft_putstr(char *s);
int		ft_check_line(char **tab);
int		ft_check_buf(char *buf);
void	ft_error(void);
int		ft_check_format(char *buf, char **tab);
t_tetri	*ft_cpy_tab(char **tab);
t_tetri	*ft_cpy_coord(t_tetri *t, int len);
int		ft_check_count(t_tetri *t, int len);
void	ft_display_tetri(t_tetri *t, int len);
t_coord	*ft_tetriminos(void);
int		ft_check_pattern(t_tetri *t, int len);
int		ft_check_valid(char *buf);

//libft.h
void	*ft_memalloc(size_t size); //
int		ft_strlen(const char *s); //
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strncat(char *s1, const char *s2, size_t n); //
char	**ft_strsplit(char const *str, char c); //

#endif
