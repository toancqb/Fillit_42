/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:13:07 by qtran             #+#    #+#             */
/*   Updated: 2017/12/18 20:52:00 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIB_H
# define _FT_LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# define BUF_SIZE 2048
# define NB_TETRI 19
# define NB_BLOCK 19
# define X 4
# define Y 4



typedef struct	s_coord
{
	int x[4];
	int y[4];
}				t_coord;

typedef struct	s_tetri
{
	int flag;
	t_coord	coord;
	char	**tab;
}				t_tetri;

typedef struct	s_map
{
	t_tetri	*t;
	char	**m;
	int		size;
	int		size_tetri;
}				t_map;

char	**ft_pattern_tetri(void);
char	**ft_init_tab(int x, int y);
void ft_del_tab(char **tab);
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
t_tetri	*ft_check_valid(char *buf, int *size_tetri);
t_map	*ft_init_map(t_tetri *t, int size);
void	ft_display_map(t_map map);
void	ft_del_map(t_map **map);
int		ft_add_tetri_to_map(t_map *map, int index, int x, int y);
int		ft_del_tetri_from_map(t_map *map, int index, int x, int y);
void ft_btracking(char *buf); //
int ft_bt(t_map *map, int k_tetri);
int ft_done(t_tetri *t, int size);//
//libft.h
void	*ft_memalloc(size_t size); //
int		ft_strlen(const char *s); //
char	*ft_strncpy(char *dst, const char *src, size_t len); //
char	*ft_strncat(char *s1, const char *s2, size_t n); //
char	**ft_strsplit(char const *str, char c); //

#endif
