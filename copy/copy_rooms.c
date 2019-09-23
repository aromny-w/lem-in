/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:36:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/23 22:25:00 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*roomdup(t_room *proom)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = ft_strdup(proom->name);
	room->coords = proom->coords;
	room->dist = 0;
	room->visited = 0;
	room->excluded = 0;
	room->num = 0;
	room->in = 0;
	room->out = 0;
	room->links = 0;
	room->link = NULL;
	room->next = NULL;
	return (room);
}

void	add_room(t_farm *new_farm, t_room *room, int in, int out)
{
	t_room	*ptr;

	ptr = (new_farm)->room;
	room->in = in;
	room->out = out;
	if (!ptr)
	{
		(new_farm)->room = room;
		return;
	}
	while (ptr)
	{
		if (ptr->next == NULL)
			break;
		ptr = ptr->next;
	}
	ptr->next = room;
}

void	copy_rooms(t_farm *new_farm, t_farm *farm)
{
	t_room	*ptr;
	t_room	*tmp;

	ptr = farm->room;
	while (ptr)
	{
		tmp = roomdup(ptr);
		if (tmp == NULL)
			terminate(-1);
		if (ptr == farm->start)
		{
			add_room(new_farm, tmp, 0, 0);
			new_farm->start = tmp;
		}
		else if (ptr == farm->end)
		{
			add_room(new_farm, tmp, 0, 0);
			new_farm->end = tmp;
		}
		else
		{
			add_room(new_farm, tmp, 1, 0);
			add_room(new_farm, roomdup(ptr), 0, 1);
		}
		ptr = ptr->next;
	}
}
