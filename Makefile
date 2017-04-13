#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 03:08:52 by yguellil          #+#    #+#              #
#    Updated: 2017/01/27 03:07:31 by aguellil         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRCS = calculations.c check_errors.c ft_list.c initializations.c resolution.c\
		compare_and_fill.c stocks.c main.c
OBJS = $(SRCS:.c=.o)

SRCS_SUL = $(SRCS:.c=.c~)
OBJS_SUL = $(OBJS:.o=.o~)

INCLUDES_DIR = ./includes/
LIBFT_DIR = libft/
SRCS_DIR = ./sources/
OBJS_DIR = ./objects/

SRC_SUL = $(addprefix $(SRCS_DIR),$(SRCS_SUL))
OBJ = $(addprefix $(OBJS_DIR),$(OBJS))
OBJ_SUL = $(addprefix $(OBJS_DIR),$(OBJS_SUL))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBFT_DIR)
	gcc $(CFLAGS) -L ./$(LIBFT_DIR) -lft $^ -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir objects 2> /dev/null || true
	gcc $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "Clean is in progress."
	make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ) $(OBJ_SUL) $(SRC_SUL) Makefile~ $(INCLUDES_DIR)$(NAME).h~

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all
