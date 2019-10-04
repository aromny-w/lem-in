/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:25:26 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/04 15:51:00 by bharrold         ###   ########.fr       */
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

typedef struct	s_path
{
	t_way			*way;
	int				len;
}				t_path;

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
	int				dist;
	int				visited;
	int				excluded;
	int				num;
	int				in; // bool
	int				out; // bool
	int				links;
	t_link			*link; // list
	struct s_room	*next;
};

typedef struct	s_farm
{
	int				ants;
	t_room			*room; // rooms]
	t_room			*start;
	t_room			*end;
	int				again;
}				t_farm;

void			lem_in(int fd);
void			readinput(t_farm *farm, int fd, char *line);
void			setroom(char *line, t_room **room);
void			setlink(char *line, t_farm *farm);
void			solvefarm(t_farm farm, size_t max);
void			splitrooms(t_room **room, t_room *start, t_room *end);
void			adjustlinks(t_room **room, t_room *start, t_room *end);
t_path			*getpaths(t_farm farm, t_path *init, size_t k);
t_path			*findpaths(t_farm farm, t_path *path, t_path *init, size_t k);
void			dfs(t_farm farm, t_path *path, t_path tmp, t_room *room);
void			terminate(int status);
void			destroyfarm(t_farm *farm);
t_room			*roomnew(char *name, t_point coords, t_link *link);
void			roomadd(t_room **room, t_room *new);
void			roomrev(t_room **room);
t_link			*linknew(t_room *room, float weight);
void			linkadd(t_link **link, t_link *new);
void			linkrev(t_link **link);
void			linkdel(t_link **link);
t_way			*waynew(t_room *room);
void			wayadd(t_way **way, t_way *new);
void			wayrev(t_way **way);
t_path			pathnew(t_way *way, size_t len);
int				isantnbr(char *line);
int				isroom(char *line, t_room *room);
int				islink(char *line, t_room *room);
int				iscommand(char *line);
int				iscomment(char *line);
void			printstatus(t_path *path, size_t k);
void			printrooms(t_room *room);
int				checkoverlap(t_path new);
void			cancelpaths(t_path *path, size_t k);


t_farm			*make_split_farm(t_farm *farm);
void			make_links(t_farm *new_farm, t_farm *farm);
void			copy_rooms(t_farm *new_farm, t_farm *farm);

/*
*********** ALGO ***************
*/

t_way			*init_way(t_room *room);
void			destroy_way(t_way *way);
t_ways			*init_ways(void);
void			destroy_ways(t_ways *ways);
void			print_way(t_way *way);
void			print_ways(t_ways *ways);
int				get_rooms_count(t_farm *farm);
t_room			*find_room_by_num(t_farm *farm, int num);
t_room			*find_room_by_name_inout(t_farm *farm, char *name,
					int in, int out);
int				find_num_by_room(t_room *room);
void			debug_print_rooms(t_farm *farm);
void			reset_dist(t_farm *farm);
int				**create_matrix(int size);
void			destroy_matrix(int **matrix, int size);
void			print_matrix(int **matrix, int size);
void			fill_matrix(int ***matrix, t_farm *farm);
void			reset_matrix(int ***matrix, int size);
int				*queue(int size);
t_room			*dequeue(int *q, t_farm *farm);
void			enqueue(int *q, int num);
int				add_way(t_ways *ways, t_farm *farm);

t_ways			*bfs (t_farm *farm);
t_ways			*suurballe(t_farm *farm);
void			suurballe_reverse_links(t_farm *farm, t_ways *ways);
void			suurballe_exclude_link(t_farm *farm, int r1, int r2);

#endif
