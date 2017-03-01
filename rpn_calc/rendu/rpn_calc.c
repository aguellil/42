/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:13:34 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/01 11:01:00 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_char_is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		ft_char_is_dg(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_char_is_dl(char c)
{
	return (c == ' ' || c == 0);
}

int		ft_rpn_nb_args(char *rpn)
{
	int	nb_args;

	if (rpn == 0)
		return (-1);
	nb_args = 0;
	if (!ft_char_is_dl(*rpn))
		nb_args++;
	while (*rpn)
	{
		if (ft_char_is_dl(*rpn) && !ft_char_is_dl(*(rpn + 1)))
			nb_args++;
		rpn++;
	}
	return (nb_args);
}

char	*ft_rpn_reach_arg_no(char *rpn, int no)
{
	int	cpt_arg;
	int	nb_args;

	nb_args = ft_rpn_nb_args(rpn);
	if (rpn == 0 || *rpn == 0 || nb_args <= 0 || no < 1 || no > nb_args)
		return (0);
	cpt_arg = 0;
	if (!ft_char_is_dl(*rpn))
		cpt_arg++;
	while (cpt_arg != no)
	{
		if (ft_char_is_dl(*rpn) && !ft_char_is_dl(*(rpn + 1)))
			cpt_arg++;
		rpn++;
	}
	return (rpn);
}

char	ft_rpn_typeof_arg_no(char *rpn, int no)
{
	char	*arg;

	arg = ft_rpn_reach_arg_no(rpn, no);
	if (arg == 0 || (!ft_char_is_op(*arg) && !ft_char_is_dg(*arg)))
		return (0);
	if (ft_char_is_op(*arg) && ft_char_is_dl(*(arg + 1)))
		return ('o');
	if (*arg != '+' && *arg != '-' && !ft_char_is_dg(*arg))
		return (0);
	arg++;
	while (!ft_char_is_dl(*arg))
	{
		if (!ft_char_is_dg(*arg))
			return (0);
		arg++;
	}
	return ('n');
}

int		ft_rpn_is_valid(char *rpn, int start, int end)
{
	int		nb_args;
	int		cpt;
	int		k;
	char	t;

	nb_args = end - start + 1;
	if (rpn == 0 || *rpn == 0 || start <= 0 || end <= 0 || \
		start > end || nb_args <= 0 || nb_args == 2)
		return (0);
	cpt = (ft_rpn_typeof_arg_no(rpn, start) == 'n');
	k = start + 1;
	while (k <= end && cpt > 0)
	{
		t = ft_rpn_typeof_arg_no(rpn, k);
		if (t != 'n' && t != 'o')
			return (0);
		cpt = cpt + (t == 'n') - (t == 'o');
		k++;
	}
	return (cpt == 1);
}

int		ft_rpn_calculate(int n1, int n2, char op, int *aerror)
{
	if (aerror == 0 || *aerror == 1)
		return (0);
	if (op == '+')
		return (n1 + n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '*')
		return (n1 * n2);
	if (op == '/' && n2 != 0)
		return (n1 / n2);
	if (op == '%' && n2 != 0)
		return (n1 % n2);
	*aerror = 1;
	return (0);
}

int		ft_rpn_calc_recursive(char *rpn, int start, int end, int *aerror)
{
	int		nb_args;
	int		k;

	if (aerror == 0 || *aerror == 1)
		return (0);
	if (!ft_rpn_is_valid(rpn, start, end))
	{
		*aerror = 1;
		return (0);
	}
	nb_args = end - start + 1;
	if (nb_args == 1)
		return (atoi(ft_rpn_reach_arg_no(rpn, start)));
	if (nb_args == 3)
	{
		return (ft_rpn_calculate(atoi(ft_rpn_reach_arg_no(rpn, start)), \
				atoi(ft_rpn_reach_arg_no(rpn, start + 1)), \
				*ft_rpn_reach_arg_no(rpn, start + 2), aerror));
	}
	if (nb_args > 3)
	{
		k = 0;
		while (!ft_rpn_is_valid(rpn, start, start + k) || \
				!ft_rpn_is_valid(rpn, start + k + 1, end - 1))
			k++;
		return (ft_rpn_calculate(\
				ft_rpn_calc_recursive(rpn, start, start + k, aerror), \
				ft_rpn_calc_recursive(rpn, start + k + 1, end - 1, aerror), \
				*ft_rpn_reach_arg_no(rpn, end), \
				aerror));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	error;
	int	result;

	error = 0;
	result = 0;
	if (argc != 2)
		error = 1;
	else
		result = ft_rpn_calc_recursive(*(argv + 1), 1, ft_rpn_nb_args(*(argv + 1)), &error);
	if (error != 0)
		printf("%s\n", "Error");
	else
		printf("%d\n", result);
	return (error);
}
