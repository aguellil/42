#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/27 00:47:30 by aguellil          #+#    #+#              #
#    Updated: 2016/02/28 22:37:19 by aguellil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Archiver
ARCHIVER_NAME = ar
ARCHIVER_FLAGS = -usr

# Compiler
COMPILER_NAME = gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

# Headers
HEADERS_DIRECTORY = ./Headers/

# Libraries
LIBRARIES_DIRECTORY = ./
LIBRARIES_NAMES = ''

# Objects
OBJECTS_DIRECTORY = $(SOURCES_DIRECTORY)
OBJECTS_NAMES = $(SOURCES_NAMES:.c=.o)
OBJECTS_PATHS = $(OBJECTS_NAMES:%=$(OBJECTS_DIRECTORY)%)

# Sources
SOURCES_DIRECTORY = ./Sources/
SOURCES_NAMES = ft_matrix_add_nb_in_col.c ft_matrix_create.c ft_matrix_free.c \
ft_matrix_print.c ft_putnbr.c ft_game.c ft_puissance4.c ft_abs.c \
ft_matrix_nb_ad_at.c ft_matrix_winner.c ft_game_read_move_player.c \
ft_ia.c ft_atoi.c ft_putstr.c ft_puissance4_arg.c\

SOURCES_PATHS = $(SOURCES_NAMES:%=$(SOURCES_DIRECTORY)%)

# Target
NAME = puissance4

# Tests
TESTS_DIRECTORY = ./Tests/
TESTS_NAMES = ''

all: $(NAME)

$(NAME): $(OBJECTS_NAMES)
	@$(COMPILER_NAME) $(COMPILER_FLAGS) $(OBJECTS_NAMES) -o $(NAME)

$(OBJECTS_NAMES): $(SOURCES_PATHS)
	@$(COMPILER_NAME) $(COMPILER_FLAGS) -c \
	-I$(HEADERS_DIRECTORY) $(SOURCES_PATHS)

clean:
	@/bin/rm -f $(OBJECTS_NAMES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

tests:

.PHONY: all clean fclean re tests
