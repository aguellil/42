#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/04 02:58:05 by tlegroux          #+#    #+#              #
#    Updated: 2017/03/04 18:20:00 by tlegroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= domino

SRC=	main.c \
		move.c \
		get_next_move.c \
		init.c \
		input.c \
		placement.c \
		cleanup.c \
		choice.c \
		list_available_moves.c \
		list_possible_moves_horizontal.c \
		list_possible_moves_vertical.c \
		make_move.c \

cc = gcc
CFLAGS += $(INCL) -Wall -Wextra -Werror -ansi -pedantic -g

OBJ= $(SRC:.c=.o)

LIBDIR=	-L./libft/
LIB=	-lft $(LIBDIR)

INCL= -I./libft/includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -vf $(OBJ)

fclean: clean
	make -C ./libft/ fclean
	rm -vf $(NAME)

re: fclean all