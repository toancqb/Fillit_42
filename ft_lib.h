/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:13:07 by qtran             #+#    #+#             */
/*   Updated: 2017/11/27 12:06:32 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIB_H
# define _FT_LIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 1024
# define NB_TETRI 19
# define NB_BLOCK 17 

void	*ft_memalloc(size_t size);
void	ft_assign_value(char **s);
char	**ft_pattern_tetri(void);
char	**ft_init_tab(int x, int y);

#endif
