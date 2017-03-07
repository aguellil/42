/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 04:23:54 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 12:51:23 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H
# define DOMINO_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct	s_domino
{
	char			n1;
	char			n2;
	char			o;
	char			d;
	int				l;
	int				c;
	struct s_domino	*next;
}				t_domino;

typedef struct	s_player
{
	int			id;
	int			score;
	t_domino	*dominoes;
}				t_player;

typedef struct	s_map
{
	char		**data;
	int			n;
	int			m;
}				t_map;

typedef struct	s_state
{
	t_player		*ai;
	t_player		*opponent;
	t_player		*current_player;
	t_player		*winner;
	t_map			*map;
}				t_state;

void			ft_char_write(char c, int fd);
void			ft_str_write(char *str, int fd);

t_map			*ft_map_create(int n, int m, char c);
void			ft_map_free(t_map *map);
void			ft_map_write(t_map *mat, int fd);

//int				ft_puissance4_arg(char **av);
//int				ft_abs(int n);
//int				ft_atoi(const char *str);
//void			ft_map_add_nb_in_col(t_map *mat, int k, int j, \
//													t_options *opts);
//int				ft_map_nb_ad_at(t_map *mat, int i, int j, int angle);
//int				ft_map_winner(t_map *mat, t_options *opts);
//void			ft_putnbr(int n);
//int				ft_game(t_options *opts);
//int				ft_game_read_move_player(t_map *mat);
//void			ft_ia(t_map *mat, int profondeur, t_options *opts);
//int				ft_max(t_map *mat, int profondeur, t_options *opts);
#endif
