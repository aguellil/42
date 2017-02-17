/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc_iterative_w_struct.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:18:21 by aguellil          #+#    #+#             */
/*   Updated: 2017/02/17 13:37:00 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

void	ft_list_add_link(t_link **alist, t_link link)
{
	t_link	*alink;
	t_link	*afirstlink;

	if (alist == 0)
		return ;
	afirstlink = *alist;
	alink = (t_link *)malloc(sizeof(t_link));
	if (alink == 0)
		return ;
	*alink = link;
	if (*alist == 0)
	{
		*alist = alink;
		return ;
	}
	while ((*alist)->next != 0)
		*alist = (*alist)->next;
	(*alist)->next = alink;
	*alist = afirstlink;
	return ;
}

void	ft_list_del_link(t_link *alink)
{
	if (!alink)
		return ;
	alink->nb = 0;
	alink->op = 0;
	alink->next = 0;
	free(alink);
	return ;
}

void	ft_list_del_links(t_link **alist)
{
	t_link	*p_link;

	if (alist == 0)
		return ;
	while (*alist != 0)
	{
		p_link = *alist;
		ft_list_del_link(*alist);
		*alist = p_link->next;
	}
	return ;
}

t_link	*ft_str_to_rpn_list(char *s)
{
	t_link	*rpnlst;
	t_link	lnk;
	int		j;
	char	c;

	if (s == 0)
		return (0);
	while (*s != 0)
	{
		while (*s == ' ')
			s++;
		if (*s != 0 && \
			(('0' <= *s && *s <= '9') || \
			((*s == '+' || *s == '-') && ('0' <= *(s + 1) && *(s + 1) <= '9'))))
		{
			lnk.nb = 0;
			lnk.op = 0;
			lnk.next = 0;
			j = 0;
			while (s[j] != 0 && s[j] != ' ')
				j++;
			c = s[j];
			s[j] = 0;
			lnk.nb = atoi(s);
			s[j] = c;
			s = s + j;
			ft_list_add_link(&rpnlst, lnk);
		}
		else
		{
			if ((*s != 0) && \
			(*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%') && \
			(*(s + 1) == ' ' || *(s + 1) == 0))
			{
				lnk.nb = 0;
				lnk.op = 0;
				lnk.next = 0;
				lnk.op = *s;
				s = s + 1;
				ft_list_add_link(&rpnlst, lnk);
			}
			else
				return (0);
		}
		while (*s == ' ')
			s++;
	}
	return (rpnlst);
}

int		ft_rpn_list_calc_sub(t_link lnk1, t_link lnk2, t_link lnk3)
{
	if (lnk3.op == '+')
		return (lnk1.nb + lnk2.nb);
	if (lnk3.op == '-')
		return (lnk1.nb - lnk2.nb);
	if (lnk3.op == '*')
		return (lnk1.nb * lnk2.nb);
	if (lnk3.op == '/')
		return (lnk1.nb / lnk2.nb);
	if (lnk3.op == '%')
		return (lnk1.nb % lnk2.nb);
	return (0);
}

int		ft_rpn_list_has_sub(t_link *rpnlst)
{
	t_link	lnk1;
	t_link	lnk2;
	t_link	lnk3;

	if (!rpnlst)
		return (0);
	if (!(rpnlst) || !(rpnlst->next) || !(rpnlst->next->next))
		return (0);
	while (rpnlst && rpnlst->next && rpnlst->next->next)
	{
		lnk1 = *(rpnlst);
		lnk2 = *(rpnlst->next);
		lnk3 = *(rpnlst->next->next);
		if (lnk1.op == 0 && lnk2.op == 0 && lnk3.op != 0)
			return (1);
		rpnlst = rpnlst->next;
	}
	return (0);
}

void	ft_rpn_list_replace_sub(t_link **arpnlst)
{
	t_link	*alnk1;
	t_link	*alnk2;
	t_link	*alnk3;
	t_link	*afirstlink;

	if (!arpnlst)
		return ;
	if (!(*arpnlst) || !((*arpnlst)->next) || !((*arpnlst)->next->next))
		return ;
	afirstlink = *arpnlst;
	while ((*arpnlst) && (*arpnlst)->next && (*arpnlst)->next->next)
	{
		alnk1 = (*arpnlst);
		alnk2 = (*arpnlst)->next;
		alnk3 = (*arpnlst)->next->next;
		if (alnk1->op == 0 && alnk2->op == 0 && alnk3->op != 0)
		{
			alnk1->nb = ft_rpn_list_calc_sub(*alnk1, *alnk2, *alnk3);
			alnk1->next = alnk3->next;
			ft_list_del_link(alnk2);
			ft_list_del_link(alnk3);
		}
		*arpnlst = (*arpnlst)->next;
	}
	*arpnlst = afirstlink;
	return ;	
}

void	ft_rpn_calc_iterative_w_struct(char *str)
{
	t_link	*rpnlst;

	rpnlst = ft_str_to_rpn_list(str);
	if (rpnlst == 0)
	{
		printf("%s\n", "Error");
		return ;
	}
	while (ft_rpn_list_has_sub(rpnlst))
		ft_rpn_list_replace_sub(&rpnlst);
	if (rpnlst->next == 0 && rpnlst->op == 0)
		printf("%d\n", rpnlst->nb);
	else
		printf("%s\n", "Error");
	ft_list_del_links(&rpnlst);
	return ;
}
