/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:01:57 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 18:43:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H

# define HOTRACE_H

# define PRINT_SIZE		2048
# define READ_SIZE		64

# define TRUE			1
# define FALSE			0

# include "stdlib.h"
# include "unistd.h"

typedef unsigned int	t_uint;
typedef int				t_bool;

/*
** list struct - simple linked list
*/
typedef struct s_list	t_list;
struct					s_list
{
	char	*key;
	char	*value;
	size_t	hash;
	t_list	*next;
};

/*
** htable struct - hash table
*/
typedef struct s_htable	t_htable;
struct					s_htable
{
	size_t	length;
	t_list	**bucket;
	size_t	bucket_size;
};

/*
** str.c
*/
void					ft_putstr(const char *s);
void					ft_puterr(const char *s);
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);

/*
** mem.c
*/
void					ft_bzero(void *s, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);

/*
** buffer.c
*/
void					add_to_buffer(char *buf, const char *s);

/*
** PARSING
** parsing.c
*/
t_bool					parsing(t_htable *table, char *print_buf);

/*
** HASH
** new_table.c
*/
t_htable				*new_table(void);

/*
** del_table.c
*/
void					del_table(t_htable *table);

/*
** set_hash.c
*/
t_bool					set_hash(t_htable *table, char *key, char *value);

/*
** get_hash.c
*/
char					*get_hash(t_htable *table, char *key);

#endif
