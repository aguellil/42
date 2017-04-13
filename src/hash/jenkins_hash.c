/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jenkins_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 00:34:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/23 02:41:57 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** good old bob jenkins's hash
** (https://en.wikipedia.org/wiki/Jenkins_hash_function)
*/

#include "hash.h"

size_t		jenkins_hash(const char *value)
{
	size_t		hash;
	const char	*swap;

	hash = 0;
	swap = value;
	while (*swap)
	{
		hash += (size_t)*(swap++);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	return (hash + (hash << 15));
}
