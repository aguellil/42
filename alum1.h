/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:11:02 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 23:04:18 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define MAX 10000
# define MAX_NUMBER_OF_MATCHES 3
# define LEAVE_LAST_MATCHES 0
# define TAKE_LAST_MATCHES 1
# define MACHINE 0
# define HUMAN 1

# include "libft/libft.h"

typedef struct		s_row
{
	int				nb_matches;
	int				strategy;
}					t_row;

int					alum1_initialize(int argc, const char **argv, \
									t_list **adata);
void				alum1_process(t_list *data, int *aerror);
void				alum1_finalize(t_list *data, int *aerror);
void				ai_implement_strategy(t_list *list);
int					ai_determine_matches_to_take(t_list *link);
int					human_answer_is_valid(char *answer, t_list *link);
int					human_ask_matches_to_take(t_list *list);
int					human_ask_first_to_play(int auth);
char				*input_read(int fd, char *str_delimiter);
void				play_turn(t_list *data, int player);
int					parser(int fd, t_list **data);
void				free_data(t_list *data);
int					ft_usage(int argc);
int					check_line(char *line);
int					ft_error(t_list *data, char **aline);
void				remove_first(t_list **list);
int					take_matches(t_list *data_row, int t);
void				print_board(t_list *data);

#endif
