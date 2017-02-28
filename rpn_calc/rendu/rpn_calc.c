/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:13:34 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/01 00:50:32 by aguellil         ###   ########.fr       */
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

int		ft_rpn_calculate(int n1, int n2, char op, int *aresult)
{
	if (aresult == 0)
		return (-1);
	if (op == '+')
		*aresult = n1 + n2;
	if (op == '-')
		*aresult = n1 - n2;
	if (op == '*')
		*aresult = n1 * n2;
	if (op == '/' && n2 != 0)
		*aresult = n1 / n2;
	if (op == '%' && n2 != 0)
		*aresult = n1 % n2;
	return (0);
}

int		ft_rpn_calc_recursive(char *rpn, int start, int end, int *aresult)
{
	int		nb_args;
	char	t1;
	char	t2;
	int		n1;
	int		n2;
	char	op;
	int		error;

	error = 0;
	nb_args = end - start + 1;
	if (rpn == 0 || *rpn == 0 || start <= 0 || end <= 0 || \
		(nb_args < 3 && nb_args != 1) || \
		(nb_args == 1 && ft_rpn_typeof_arg_no(rpn, start) != 'n') || \
		(nb_args >= 3 && (ft_rpn_typeof_arg_no(rpn, start) != 'n' || ft_rpn_typeof_arg_no(rpn, start + 1) != 'n' || ft_rpn_typeof_arg_no(rpn, end) != 'o')))
		return (1);
	if (nb_args == 1)
		*aresult = atoi(ft_rpn_reach_arg_no(rpn, start));
	if (nb_args == 3)
	{
		ft_rpn_calculate(atoi(ft_rpn_reach_arg_no(rpn, start)), \
						atoi(ft_rpn_reach_arg_no(rpn, start + 1)), \
						*ft_rpn_reach_arg_no(rpn, start + 2), aresult);
	}
	if (nb_args > 3)
	{
		t1 = ft_rpn_typeof_arg_no(rpn, start + 2);
		t2 = ft_rpn_typeof_arg_no(rpn, end - 1);
		error = ft_rpn_calc_recursive(rpn, start, (start + 2 * (t1 == 'o')) * (t2 == 'o') + (end - 2) * (t2 == 'n'), &n1);
		error = error || ft_rpn_calc_recursive(rpn, (start + 2 * (t1 == 'o')) * (t2 == 'o') + (end - 2) * (t2 == 'n') + 1, end - 1, &n2);
		op = *(ft_rpn_reach_arg_no(rpn, end));
		if (error == 0)
			ft_rpn_calculate(n1, n2, op, aresult);
	}
	return (error);
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
		error = ft_rpn_calc_recursive(*(argv + 1), 1, ft_rpn_nb_args(*(argv + 1)), &result);
	if (error != 0)
		printf("%s\n", "Error");
	else
		printf("%d\n", result);
	return (error);
}
