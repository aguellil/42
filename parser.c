/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:23:56 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 22:59:05 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		parser_line(char *line, t_list **data)
{
	int			nb;
	t_row		*row;
	t_list		*lst;

	if (!check_line(line))
		return (0);
	if ((nb = ft_atoi(line)) > 0 && nb <= MAX)
	{
		if (!(row = (t_row*)malloc(sizeof(t_row))))
			return (0);
		row->nb_matches = nb;
		if (!(lst = ft_lstnew((void const*)row, sizeof(t_row))))
		{
			free(row);
			return (0);
		}
		if (row)
			free(row);
		ft_lstadd(data, lst);
	}
	else
		return (0);
	return (1);
}

static int		parser_file(int fd, t_list **data)
{
	char		*line;
	int			empty_file;

	empty_file = 1;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		empty_file = 0;
		if (!parser_line(line, data))
			return (ft_error(*data, &line));
		ft_strfree(&line);
	}
	ft_strfree(&line);
	if (empty_file)
		return (ft_error(*data, &line));
	return (empty_file ? ft_error(*data, &line) : 1);
}

static int		content_empty(int content, t_list *data, char **aline)
{
	if (!content)
		return (ft_error(data, aline));
	ft_strfree(aline);
	return (1);
}

static int		parser_input(t_list **data)
{
	char		*line;
	int			content_exist;

	content_exist = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) == 0)
			return (content_empty(content_exist, *data, &line));
		content_exist = 1;
		if (!parser_line(line, data))
			return (ft_error(*data, &line));
		ft_strfree(&line);
	}
	ft_strfree(&line);
	return (!content_exist ? ft_error(*data, &line) : 1);
}

int				parser(int fd, t_list **data)
{
	int			ret;

	if (fd == 0)
		ret = parser_input(data);
	else
		ret = parser_file(fd, data);
	return (ret);
}
