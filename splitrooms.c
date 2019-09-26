/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitrooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:18:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/26 11:14:51 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*getendroom(t_room *room)
{
	t_link	*tmp;

	tmp = room->link;
	while (tmp)
	{
		tmp->weight = INFINITY;
		if (tmp->room->in)
			linkadd(&room->link, linknew(tmp->room->link->room, INFINITY));
		tmp = tmp->next;
	}
	return (room);
}

static t_room	*getroomout(t_room *room)
{
	t_room	*out;
	t_link	*tmp;

	out = roomnew(room->name, room->coords, NULL);
	out->out = 1;
	tmp = room->link;
	while ((tmp = tmp->next))
		linkadd(&out->link, linknew(tmp->room, 1));
	linkrev(&out->link);
	return (out);
}

static t_room	*getroomin(t_room *room)
{
	t_room	*in;
	t_link	*tmp;

	in = room;
	in->in = 1;
	in->links = 1;
	tmp = in->link;
	while (tmp)
	{
		tmp->weight = INFINITY;
		tmp = tmp->next;
	}
	return (in);
}

static t_room	*getsplitroom(t_room *room)
{
	t_room	*in;
	t_room	*out;

	in = getroomin(room); //fix here asap
	out = getroomout(room);
	linkadd(&in->link, linknew(out, 0));
	linkadd(&out->link, linknew(in, INFINITY));
	out->next = in->next;
	in->next = out;
	return (in);
}

void			splitrooms(t_room **room, t_room *start, t_room *end)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp == end)
			tmp = getendroom(tmp);
		if (tmp != start && tmp != end)
		{
			tmp = getsplitroom(tmp);
			tmp = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
}
