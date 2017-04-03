#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 10:51:23 by aguellil          #+#    #+#              #
#    Updated: 2017/04/02 21:36:33 by aguellil         ###   ########.fr        #
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
HEADERS_FLAGS = -I$(HEADERS_DIRECTORY)

# Libraries
LIBRARIES_DIRECTORY = .
LIBRARIES_NAMES = ''
LIBRARIES_FLAGS	= $(subst lib,-l,$(patsubst %.a,%,$(LIBRARIES_NAMES)))

# Objects
OBJECTS_DIRECTORY = .
OBJECTS_NAMES = $(SOURCES_NAMES:%.c=%.o)
OBJECTS_PATHS = $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(OBJECTS_NAMES))

# Platform
PLATFORM_NAME = macos
PLATFORM_FLAGS = $(MACOS_FLAGS)
MACOS_FLAGS = ''
LINUX_FLAGS = ''

# Sources
SOURCES_DIRECTORY = .
SOURCES_NAMES = ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memcpy_rev.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strfree.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_isprint.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				get_next_line.c \
				ft_swap.c
SOURCES_PATHS = $(patsubst %,$(SOURCES_DIRECTORY)/%,$(SOURCES_NAMES))

# Target
NAME = libft.a

all: $(PLATFORM_NAME) $(NAME)
	@true;

$(NAME): $(OBJECTS_PATHS)
	@$(ARCHIVER_NAME) $(ARCHIVER_FLAGS) $(NAME) $(OBJECTS_NAMES) 2>/dev/null;

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@if [ ! -d $(OBJECTS_DIRECTORY) ]; then mkdir $(OBJECTS_DIRECTORY); fi
	@$(COMPILER_NAME) $(COMPILER_FLAGS) $(HEADERS_FLAGS) -c $< -o $@;

clean:
	@/bin/rm -rf $(OBJECTS_PATHS);

fclean: clean
	@/bin/rm -f $(NAME);

re: fclean all

macos: ;

linux: macos

.PHONY: all clean fclean re macos linux
