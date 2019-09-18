/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 17:02:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*getsplitroom(t_room *room)
{
	t_room	*in;
	t_room	*out;

	in = room;
	in->in = 1;
	if (!(out = (t_room *)malloc(sizeof(t_room))))
		terminate(-1);
	out->name = in->name;
	out->coords = in->coords;
	out->in = 0;
	out->out = 1;
	out->dist = in->dist;
	out->links = in->links;
	out->link = in->link;
	out->next = in->next;
	in->links = 1;
	if (!(in->link = (t_link *)malloc(sizeof(t_link))))
		terminate(-1);
	in->link->room = out;
	in->link->weight = 0;
	in->link->next = NULL;
	in->next = out;
	return (in);
}

static void		splitrooms(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		tmp = getsplitroom(tmp);
		tmp = tmp->next->next;
	}
}

static size_t	getminvalue(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	solvefarm(t_farm *farm)
{
	t_path	*path[1 + getminvalue(farm->ants, farm->end->links)];
	int		k;

	k = 0;
	path[k++] = NULL;
	splitrooms(&farm->room);
	while (k < farm->ants + 1)
	{
		path[k] = getpaths(*farm, path[k - 1], k);
		printstatus(&path[k], k);
		if (!path[k++])
			break ;
	}
}
