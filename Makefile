#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 10:51:23 by aguellil          #+#    #+#              #
#    Updated: 2017/04/02 03:34:31 by aguellil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Archiver
ARCHIVER_NAME = ar
ARCHIVER_FLAGS = -usr

# Compiler
COMPILER_NAME = gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

# Headers
HEADERS_DIRECTORY = .
HEADERS_FLAGS = -I$(HEADERS_DIRECTORY) \
				-I$(LIBRARIES_DIRECTORY)/libft/

# Libraries
LIBRARIES_DIRECTORY = .
LIBRARIES_NAMES = libft.a
LIBRARIES_FLAGS	= -L$(LIBRARIES_DIRECTORY)/libft/ \
				$(subst lib,-l,$(patsubst %.a,%,$(LIBRARIES_NAMES)))

# Objects
OBJECTS_DIRECTORY = Objects
OBJECTS_NAMES = $(SOURCES_NAMES:%.c=%.o)
OBJECTS_PATHS = $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(OBJECTS_NAMES))

# Platform
PLATFORM_NAME = macos
PLATFORM_FLAGS = $(MACOS_FLAGS)
MACOS_FLAGS = ''
LINUX_FLAGS = ''

# Sources
SOURCES_DIRECTORY = .
SOURCES_NAMES = alum1.c \
				ai.c \
				human.c \
				input.c \
				error.c \
				parser.c \
				play.c \
				print.c \
				tools.c
SOURCES_PATHS = $(patsubst %,$(SOURCES_DIRECTORY)/%,$(SOURCES_NAMES))

# Target
NAME = alum1

all: $(PLATFORM_NAME) $(NAME)

$(NAME): $(OBJECTS_PATHS)
	@$(COMPILER_NAME) $(COMPILER_FLAGS) $(OBJECTS_PATHS) -o $(NAME) \
	$(PLATFORM_FLAGS) $(LIBRARIES_FLAGS)

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@if [ ! -d $(OBJECTS_DIRECTORY) ]; then mkdir $(OBJECTS_DIRECTORY); fi
	@$(COMPILER_NAME) $(COMPILER_FLAGS) $(HEADERS_FLAGS) -c $< -o $@;

clean:
	@make clean -C $(LIBRARIES_DIRECTORY)/libft/;
	@/bin/rm -rf $(OBJECTS_DIRECTORY);

fclean: clean
	@make fclean -C $(LIBRARIES_DIRECTORY)/libft/;
	@/bin/rm -f $(NAME);

re: fclean all

macos:
	@make -C $(LIBRARIES_DIRECTORY)/libft;

linux: macos

.PHONY: all clean fclean re macos linux
