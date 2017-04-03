/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 21:36:25 by aguellil          #+#    #+#             */
/*   Updated: 2017/04/02 18:13:00 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		input_add_buffer(int fd, char **ainput, char *buffer)
{
	int		bytes_count;
	char	*tmp;

	if ((bytes_count = read(fd, buffer, BUFF_SIZE)) == -1)
	{
		free(*ainput);
		return (-1);
	}
	buffer[bytes_count] = 0;
	if (!(tmp = ft_strjoin(*ainput, buffer)))
	{
		free(*ainput);
		return (-1);
	}
	free(*ainput);
	*ainput = tmp;
	return (bytes_count);
}

static	int		input_is_finished(char *input, char *str_delimiter, \
									int bytes_added)
{
	if (str_delimiter == 0)
		return (bytes_added == 0);
	else
		return (ft_strstr(input, str_delimiter) != 0);
}

char			*input_read(int fd, char *str_delimiter)
{
	char	*input;
	char	buffer[BUFF_SIZE + 1];
	int		bytes_added;

	if (!(input = (char *)malloc(1)))
		return (0);
	*input = 0;
	if ((bytes_added = input_add_buffer(fd, &input, buffer)) == -1)
		return (0);
	while (!input_is_finished(input, str_delimiter, bytes_added))
	{
		if ((bytes_added = input_add_buffer(fd, &input, buffer)) == -1)
			return (0);
	}
	return (input);
}
