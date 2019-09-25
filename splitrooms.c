/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitrooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 23:18:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 15:36:15 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*getroomout(t_room *room)
{
	t_room	*out;

	out = roomnew(room->name, room->coords, room->link);
	out->out = 1;
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
	in->link = linknew(out, 0);
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
		if (tmp != start && tmp != end)
		{
			tmp = getsplitroom(tmp);
			tmp = tmp->next->next;
		}
		else
			tmp = tmp->next;
	}
}