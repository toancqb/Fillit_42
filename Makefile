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

NAME =fillit

CC = gcc

OPTIONS = -c

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = main.c ft_string_process.c ft_check_valid.c ft_display.c ft_map.c \
		  ft_fillit.c ft_check_format.c

OBJ=$(SRC:.c=.o)

HEAD_DIR = libft/

all: $(NAME)

$(NAME): $(OBJ) Makefile
	@$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	@(cd $(HEAD_DIR) && $(MAKE) libft.a)
	@$(CC) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@(cd $(HEAD_DIR) && $(MAKE) $@)

fclean:
	@(cd $(HEAD_DIR) && $(MAKE) $@)
	@$(RM) $(OBJ)
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
