#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2016/04/24 18:46:11 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	hotrace

C_SRC = main.c str.c mem.c buffer.c
C_PARS = parsing.c get_line.c
C_HASH = new_table.c del_table.c set_hash.c get_hash.c jenkins_hash.c

O_DIR = obj
VPATH =	src:src/parsing:src/hash

OBJS =	$(C_SRC:%.c=$(O_DIR)/%.o)	$(C_PARS:%.c=$(O_DIR)/%.o)		\
		$(C_HASH:%.c=$(O_DIR)/%.o)
DEPS =  $(OBJS:%.o=%.d)

I_DIR =		-I./inc/
MAKE =		make -j
RM =		rm -rf
MKDIR =		mkdir -p
CC =		clang
CFLAGS =	-Wall -Wextra -Werror -O2

WHITE =	\033[37;01m
RED =	\033[31;01m
GREEN =	\033[32;01m
BLUE =	\033[34;01m
BASIC =	\033[0m

.PHONY: all debug sanitize me_cry clean fclean re

all:
	@$(MAKE) $(NAME)

debug:
	@$(MAKE) $(NAME) "CFLAGS = -g -ggdb -O2"

sanitize:
	@$(MAKE) $(NAME) \
		"CFLAGS = -g -ggdb -O2 -fsanitize=address,undefined -ferror-limit=5"

me_cry:
	@$(MAKE) $(NAME) \
		"CFLAGS = -Wpedantic -Wshadow -Wconversion -Wcast-align \
-Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code -Winit-self \
-Wmissing-declarations -Wfloat-equal -Wbad-function-cast -Wundef \
-Waggregate-return -Wstrict-overflow=5 -Wold-style-definition -Wpadded \
-Wredundant-decls -Wall -Werror -Wextra -O2"

-include $(DEPS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(I_DIR) $(OBJS) -o $@
	@echo "$(BLUE)$(OBJS) $(WHITE)->$(RED) $@ $(BASIC)"
	@echo "$(WHITE)flags:$(BASIC) $(CFLAGS)"
	@echo "$(WHITE)compi:$(BASIC) $(CC)"

$(O_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(I_DIR) -MMD -c $< -o $@
	@echo "$(WHITE)$<\t->$(BLUE) $@ $(BASIC)"

$(OBJS): | $(O_DIR)

$(O_DIR):
	@$(MKDIR) $(O_DIR)

clean:
	@$(RM) $(O_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
