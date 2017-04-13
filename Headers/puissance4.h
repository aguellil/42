/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 13:07:57 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 23:06:48 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_options
{
	int			height;
	int			width;
	int			height_max;
	int			width_max;
	int			win_nb;
	int			winner;
	int			nb_players;
	int			current_player;
	int			nb_moves;
	int			last_move_row;
	int			last_move_column;
}				t_options;

typedef struct	s_matrix
{
	int			**data;
	int			n;
	int			m;
}				t_matrix;

int				ft_puissance4_arg(char **av);
int				ft_abs(int n);
int				ft_atoi(const char *str);
void			ft_matrix_add_nb_in_col(t_matrix *mat, int k, int j, \
													t_options *opts);
int				ft_matrix_nb_ad_at(t_matrix *mat, int i, int j, int angle);
t_matrix		*ft_matrix_create(int n, int m);
void			ft_matrix_free(t_matrix *mat);
void			ft_matrix_print(t_matrix *mat);
int				ft_matrix_winner(t_matrix *mat, t_options *opts);
void			ft_putnbr(int n);
void			ft_putstr(char const *str);
int				ft_game(t_options *opts);
void			ft_putchar(char c);
int				ft_game_read_move_player(t_matrix *mat);
void			ft_ia(t_matrix *mat, int profondeur, t_options *opts);
int				ft_max(t_matrix *mat, int profondeur, t_options *opts);

#endif
