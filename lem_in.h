/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:25:26 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/20 22:24:13 by aromny-w         ###   ########.fr       */
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
	float			weight;	
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
	t_list			*buf;
}				t_farm;

void			lem_in(int fd);
void			readinput(t_farm *farm, int fd, char *line);
void			setroom(char *line, t_room **room);
void			setlink(char *line, t_farm *farm);
void			solvefarm(t_farm farm, size_t max);
void			splitrooms(t_room **room, t_room *start, t_room *end);
void			adjustlinks(t_room **room, t_room *start, t_room *end);
t_path			*getpaths(t_farm farm, t_path *init, size_t k);
t_path			*findpaths(t_farm farm, t_path *path, size_t k);
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
void			printstatus(t_path *path, int k);
void			printrooms(t_room *room);
int				checkoverlap(t_path new);
void			cancelpaths(t_path *path, t_path new, size_t k);
void			sortpaths(t_path *path, size_t k);
void			ants_move(t_path *path, int k, t_farm *farm);

#endif
