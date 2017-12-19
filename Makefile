# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:00:48 by qtran             #+#    #+#              #
#    Updated: 2017/12/19 17:18:15 by qtran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_lib.h

SRC = main.c ft_string_process.c ft_check_valid.c ft_display.c ft_map.c \
	  ft_fillit.c ft_check_format.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all

