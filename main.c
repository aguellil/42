/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:14:39 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/31 17:22:47 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <alcu.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char buffer[512];

	while (read(0, buffer, 512))
		printf("%s\n", buffer);
	return (0);
}
