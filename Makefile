#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/08/27 00:47:30 by aguellil          #+#    #+#              #
#    Updated: 2016/01/29 02:04:38 by aguellil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Compiler
COMPILER_NAME = gcc
COMPILER_FLAGS = -Wall -Wextra -Werror

# Archiver
ARCHIVER_NAME = ar
ARCHIVER_FLAGS = -usr

# Headers
HEADERS_DIRECTORY = ./

# Libraries
LIBRARIES_DIRECTORY = ./
LIBRARIES_NAMES = ''

# Sources
SOURCES_DIRECTORY = ./
SOURCES_NAMES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c \
ft_lstcat_bonus.c ft_lstdel.c ft_lstdelone.c ft_lstfetch_bonus.c \
ft_lstfld_bonus.c ft_lstiter.c ft_lstlen_bonus.c ft_lstmap.c ft_lstnew.c \
ft_lstprintn_bonus.c ft_lstrev_bonus.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtolst_bonus.c ft_strtrim.c ft_tolower.c \
ft_toupper.c

# Objects
OBJECTS_NAMES = $(SOURCES_NAMES:.c=.o)

# Target
NAME = libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJECTS_NAMES)
	$(ARCHIVER_NAME) $(ARCHIVER_FLAGS) $(NAME) $(OBJECTS_NAMES)

$(OBJECTS_NAMES): $(SOURCES_NAMES:%=$(SOURCES_DIRECTORY)%)
	@$(COMPILER_NAME) $(COMPILER_FLAGS) -c \
	-I$(HEADERS_DIRECTORY) \
	$(SOURCES_NAMES:%=$(SOURCES_DIRECTORY)%)

clean:
	@/bin/rm -f $(OBJECTS_NAMES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
