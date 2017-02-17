/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:48:14 by aguellil          #+#    #+#             */
/*   Updated: 2017/02/17 12:27:29 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
# define RPN_CALC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define METHOD ft_rpn_calc_iterative_w_struct

typedef struct s_link	t_link;

struct	s_link
{
	int		nb;
	char	op;
	t_link 	*next;
};

void	ft_list_add_link(t_link **alist, t_link link);
void	ft_list_del_link(t_link *alink);
void	ft_list_del_links(t_link **alist);
int		ft_rpn_list_calc_sub(t_link lnk1, t_link lnk2, t_link lnk3);
int		ft_rpn_list_has_sub(t_link *rpnlst);
void	ft_rpn_list_replace_sub(t_link **arpnlst);
void	ft_rpn_calc_iterative_w_struct(char *str);

#endif
