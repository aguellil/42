/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:43:26 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 17:58:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** todo
*/

#include "parsing.h"

static void		handle_search(t_htable *table, char *key, char *print_buf)
{
	char		*value;

	if (!(value = get_hash(table, key)))
	{
		add_to_buffer(print_buf, key);
		add_to_buffer(print_buf, ": Not found.\n");
	}
	else
	{
		add_to_buffer(print_buf, value);
		add_to_buffer(print_buf, "\n");
	}
	free(key);
}

t_bool			parsing(t_htable *table, char *print_buf)
{
	char		*line;
	char		*prev;

	prev = NULL;
	while (get_line(&line))
	{
		if (!prev && !*line && prev != (char *)(unsigned long)-42)
		{
			prev = (char *)(unsigned long)-42;
			free(line);
		}
		else if (!prev)
			prev = line;
		else if (prev == (char *)(unsigned long)-42)
			handle_search(table, line, print_buf);
		else
		{
			set_hash(table, prev, line);
			prev = NULL;
		}
	}
	return (TRUE);
}
