/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:49:19 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 18:30:11 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H
# define DOMINO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <unistd.h>

/*
** STRUCTURES:
*/
typedef struct	s_domino
{
	unsigned char	n1;
	unsigned char	n2;
	int				x;
	int				y;
	char			orientation;
	char			direction;
}				t_domino;

# define DEPTH 10

# define PLAY 0
# define DRAW 1
# define SULK 2

# define VERTICAL 1
# define HORIZONTAL 2

# define UP 1
# define LEFT 1
# define DOWN 2
# define RIGHT 2


/*
** data about an extremity of the map
*/

typedef struct	s_extremity
{
	unsigned int	x;
	unsigned int	y;
	int				value;
	t_domino		*domino;
}				t_extremity;

/*
** A struct containing datas about a player's move.
**
** action is an ID enum for play, draw, sulk
** if action is play, domino, its position, orientation and direction
** are set to the correct values..
*/

typedef struct	s_move
{
	char			player;
	char			action;
	t_domino		*domino;
	t_extremity		*parent;
}				t_move;

/*
** A struct containg the map in its current (or simulated) state.
** map is a double array for collision checks, and extremities a list of all
** available "connexion" points.
*/

typedef struct	s_board
{
	size_t			xsize;
	size_t			ysize;
	char 			**map;
	t_list			*extremities;
}				t_board;

/*
** A struct containing player datas.
*/

typedef struct	s_player
{
	int				id;
	unsigned int	score;
	t_list			*hand;
}				t_player;

typedef struct	s_gamestate
{
	int				scoredif;
	t_player		*player;
	t_player		*opponent;
	t_board			*board;
	t_list			*movelist;
}				t_gamestate;

/*
** Initializess gamestate from vm provided data
** and load the player's hand.
*/
int				init(t_gamestate *gamestate);

/*
** Parses the input given by the virtual machine
** and store all relevant information in some structures
*/
int				vm_input_parse(char *input, t_gamestate *agamestate);

/*
** Updates gamestate from vm provided data about player2's move.
** RETURN: 1 if gameover, 0 else.
*/
int				get_next_move(t_gamestate *gamestate);
t_move			*select_best_move(t_gamestate *gamestate);
t_move			*make_move(t_extremity *extremity, t_domino *child);

/*
** Returns a list of all valid moves from the hand and current gamestate.
*/
t_list			*list_available_moves(t_list *hand, t_gamestate *gamestate);
t_list			*list_vertical_moves(t_extremity *extremity, t_domino *child);
t_list			*list_horizontal_moves(t_extremity *extremity, t_domino *child);
t_list			*list_vertical_moves_flipped(t_extremity *extremity, t_domino *child);
t_list			*list_horizontal_moves_flipped(t_extremity *extremity, t_domino *child);

/*
** Checks if move is valid.
*/
int				is_move_valid(const t_move *move, const t_gamestate *gamestate);

/*
** Play or cancel a move on the gamestate.
** third option is a bool to silence the function (test mode) on 1
** or comunicate changes to the vm  (real mode) on 0.
*/
void			play_move(const t_move *move, t_gamestate *g, int s);
void			cancel_move(const t_move *last_move, t_gamestate *gamestate);

/*
** Applies the MiniMax algorithm to determine what's the best next move
*/
int				minimax(t_gamestate *g, unsigned int depth, int m, t_move **p);

/*
** cleanup functions
*/
void			free_map(t_board *board);
void			free_player(t_player *aplayer);
void			free_board(t_board *aboard);
void			clean_extremities(t_board *board);
void			cleanup(const t_gamestate *gamestate);

#endif
