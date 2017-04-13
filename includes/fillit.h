/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 03:12:09 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/27 03:05:12 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 21
# define T_MAX 4
# define EMPTY '.'

# include <sys/types.h>

typedef struct	s_tetri
{
	unsigned char		w;
	unsigned char		x;
	unsigned char		y;
	unsigned char		z;
	unsigned char		letter;
	struct s_tetri		*next;
	struct s_tetri		*prev;
}				t_tetri;

/*
** libft.a
*/
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putstr(char *str);
size_t			ft_strnlen(const char *s, size_t maxlen);

/*
** In calculations.c
*/
int				ft_min_square_side(int nb_tetriminos);
unsigned char	ft_pow(unsigned char nb, int pow);
unsigned char	ft_max(unsigned char c1, unsigned char c2);
char			ft_focus_first_bit(unsigned char bin1, unsigned char bin2);
int				ft_search_last_one_in_bin(unsigned char bin, int nb_bits);

/*
** In check_errors.c
*/
void			ft_launch_error(char *reason, int fd);
void			ft_launch_error_lst(t_tetri *list, int fd);
int				ft_sharps_links(char *buf, ssize_t i);
void			ft_ctrl_tetri(int fd, char *buf, ssize_t ret, int *count_tetri);
void			ft_ctrl_file(int fd, int *count_tetri);

/*
** In initializations.c
*/
t_tetri			ft_initialize_tetri(t_tetri tetri, char letter);
char			*ft_initialize_square(char *str, int len, int square_s);

/*
** In ft_list.c
*/
void			ft_add_link_to_end(t_tetri **list, t_tetri tetri);
void			ft_lstdel(t_tetri **first);

/*
** In stocks.c
*/
void			ft_optimize_lines(t_tetri *tetri);
void			ft_optimize_columns(t_tetri *tetri);
t_tetri			ft_optimize_stock(t_tetri tetri);
t_tetri			ft_stock_tetri_in_bits(char *buf, ssize_t i, t_tetri tetri);
void			ft_stock_tetriminos(int fd, t_tetri **list);

/*
** In compare_and_fill.c
*/
int				ft_meet_up(unsigned char bin, char *cur);
void			ft_fill_it(unsigned char bin, char *cur, char letter, int i);
void			ft_fill_sq(t_tetri *list, char *sq, char ltr, int len_line);
int				ft_compare(t_tetri *list, char *cur, int len_line);

/*
** In resolution.c
*/
int				ft_ctrl_space(t_tetri *list, char *cur, int len_l, int last_u);
char			*ft_prev(t_tetri **list, char *sq, char ***coord);
void			ft_next(t_tetri **list, char *sq, char ***coord);
t_tetri			*ft_analyze(t_tetri *lst, char *sq, char **coord, int len_line);
t_tetri			*ft_resolve(t_tetri *list, int square_s, int nb_tetri);

#endif
