/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:09:45 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/26 22:51:08 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_matrix_free(t_matrix *mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (i < mat->n)
	{
		free(mat->data[i]);
		i++;
	}
	free(mat->data);
	free(mat);
	mat = 0;
	return ;
}
