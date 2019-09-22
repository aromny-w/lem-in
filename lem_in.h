/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:25:26 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/20 18:15:15 by bharrold         ###   ########.fr       */
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
	struct s_way	*next;
}				t_way;

typedef struct	s_path
{
	t_way			*way;
	size_t			len;
}				t_path;

typedef struct	s_link
{
	t_room			*room;
	double			weight;
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
	int				in; // bool
	int				out; // bool
	double			dist;
	int				visited;
	size_t			links;
	t_link			*link; // list
	struct s_room	*next;
};

typedef struct	s_farm
{
	int				ants;
	t_room			*room; // rooms
	t_room			*start;
	t_room			*end;
}				t_farm;

void			lem_in(int fd);
void			readinput(t_farm *farm, int fd, char *line);
void			terminate(int status);
t_room			*roomnew(char *line);
void			setroom(char *line, t_room **room);
void			setlink(char *line, t_farm *farm);
void			solvefarm(t_farm *farm);
t_path			*getpaths(t_farm farm, t_path *init, size_t k);
t_path			*findpaths(t_farm farm, t_path *path, t_path *init, size_t k);
void			setpath(t_farm farm, t_path *path, t_path tmp, t_room *room);
t_way			*waynew(t_room *room);
void			wayadd(t_way **way, t_way *new);
void			wayrev(t_way **way);
t_path			pathnew(t_way *way, size_t len);
void			printstatus(t_path *path, int k);
void			destroyfarm(t_farm *farm);
int				isantnbr(char *line);
int				isroom(char *line, t_farm farm);
int				islink(char *line, t_farm farm);
t_path			*bfs (t_farm *farm);

#endif
