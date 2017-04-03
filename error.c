/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 23:33:36 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 21:40:32 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_usage(int argc)
{
	if (argc > 2)
	{
		ft_putendl("usage: ./alum1 fileName");
		return (0);
	}
	return (1);
}

int		check_line(char *line)
{
	if (ft_strlen(line) == 0)
		return (0);
	while (*line && *line != '\n')
	{
		if (!ft_isdigit((int)*line))
			return (0);
		line++;
	}
	return (1);
}

int		ft_error(t_list *data, char **aline)
{
	ft_strfree(aline);
	if (data)
		free_data(data);
	data = NULL;
	ft_putendl("ERROR");
	return (0);
}
