/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:25:26 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/07 08:38:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_room	t_room;

typedef struct	s_way
{
	t_room			*room;
	int				ant;
	int				suurbale;
	struct s_way	*next;
}				t_way;

typedef struct	s_ways
{
	int				dist;
	t_way			*way;
	struct s_ways	*next;
}				t_ways;

typedef struct	s_link
{
	t_room			*room;
	float			weight;
	int				visited;
	int				excluded;
	struct s_link	*next;
}				t_link;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

struct			s_room
{
	char			*name;
	t_point			coords;
	float			dist;
	int				visited;
	int				excluded;
	int				num;
	int				in;
	int				out;
	int				links;
	t_link			*link;
	struct s_room	*next;
};

typedef struct	s_farm
{
	int				ants;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	int				again;
}				t_farm;

void			lem_in(int fd);
void			terminate(int status);
void			destroyfarm(t_farm *farm);
void			destroyfarmways(t_farm *farm, t_ways *ways, char **out);
void			free_ways(t_ways *ways);

/*
*************** VALIDATE & READ
*/
void			readinput(t_farm *farm, int fd, char *line, char **out);
int				isantnbr(char *line);
int				isroom(char *line, t_room *room);
int				islink(char *line, t_room *room);
int				iscommand(char *line);
int				iscomment(char *line);
void			setroom(char *line, t_room **room);
void			setlink(char *line, t_farm *farm);
t_link			*linknew(t_room *room, float weight);
void			linkadd(t_link **link, t_link *new);
void			linkrev(t_link **link);
void			linkdel(t_link **link);
t_room			*roomnew(char *name, t_point coords, t_link *link);
void			roomadd(t_room **room, t_room *new);
void			roomrev(t_room **room);
t_way			*waynew(t_room *room);
void			wayadd(t_way **way, t_way *new);

/*
*************** WAYS
*/
t_way			*init_way(t_room *room);
int				add_way(t_ways *ways, t_farm *farm);
void			destroy_way(t_way *way);
t_ways			*init_ways(void);
void			destroy_ways(t_ways *ways);
void			print_way(t_way *way);
void			print_ways(t_ways *ways);

/*
*************** MATRIX
*/
int				**create_matrix(int size);
void			destroy_matrix(int **matrix, int size);
void			print_matrix(int **matrix, int size);
void			fill_matrix(int ***matrix, t_farm *farm);
void			reset_matrix(int ***matrix, int size);

/*
*************** QUEUE
*/
int				*queue(int size);
t_room			*dequeue(int *q, t_farm *farm);
void			enqueue(int *q, int num);

/*
*************** ROOMS_METHODS
*/

int				get_rooms_count(t_farm *farm);
t_room			*find_room_by_num(t_farm *farm, int num);
t_room			*find_room_by_name_inout(t_farm *farm, char *name,
					int in, int out);
int				find_num_by_room(t_room *room);
void			debug_print_rooms(t_farm *farm);

/*
*************** ALGO ***************
*/

t_ways			*bfs_dist(t_farm *farm);
void			lets_go(t_farm *farm, t_ways *ways, int ants, t_ways *begin);
void			all_ants_one_way(t_farm *farm, t_ways *ways);
void			reset_dist(t_farm *farm);

#endif
