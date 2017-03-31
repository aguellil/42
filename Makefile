#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 10:51:23 by aguellil          #+#    #+#              #
#    Updated: 2017/03/31 17:08:40 by aguellil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Archiver
ARCHIVER_NAME = ar
ARCHIVER_FLAGS = -usr

# Compiler
COMPILER_NAME = gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

# Headers
HEADERS_DIRECTORY = Headers
HEADERS_FLAGS = -I./$(HEADERS_DIRECTORY)

# Libraries
LIBRARIES_DIRECTORY = Libraries
LIBRARIES_NAMES = libft.a libglfw3.a
LIBRARIES_FLAGS	= -L./$(LIBRARIES_DIRECTORY)/libft/ \
				-L./$(LIBRARIES_DIRECTORY)/glfw/src/ \
				$(subst lib,-l,$(patsubst %.a,%,$(LIBRARIES_NAMES)))

# Objects
OBJECTS_DIRECTORY = Objects
OBJECTS_NAMES = $(SOURCES_NAMES:%.c=%.o)
OBJECTS_PATHS = $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(OBJECTS_NAMES))

# Platform
PLATFORM_NAME = macos
PLATFORM_FLAGS = ''
MACOS_FLAGS = -framework Cocoa -framework CoreVideo \
			-framework IOKit -framework OpenGL -framework GLUT
LINUX_FLAGS = ''

# Sources
SOURCES_DIRECTORY = Sources
SOURCES_NAMES = 
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
	@/bin/rm -rf $(OBJECTS_DIRECTORY);

fclean: clean
	@/bin/rm -f $(NAME);

macos: linux

linux:

re: fclean all

.PHONY: all clean fclean re macos linux
