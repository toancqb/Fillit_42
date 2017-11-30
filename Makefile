# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qtran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:00:48 by qtran             #+#    #+#              #
#    Updated: 2017/11/29 15:11:40 by qtran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_lib.h

SRC = main.c ft_string_process.c ft_check_valid.c ft_display.c ft_pattern.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
