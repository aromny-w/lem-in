/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:37:20 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/23 22:04:16 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_room *room, t_room *dest_room)
{
	t_link	*link;
	t_link	*ptr;
	
	link = (t_link*)malloc(sizeof(t_link));
	link->next = NULL;
	link->room = dest_room;
	ptr = room->link;
	while (ptr && ptr->next)
		ptr= ptr->next;
	if (!ptr)
		room->link = link;
	else
		ptr->next = link;
}

void	copy_links(t_farm *new_farm, t_room *new_room, t_room *room)
{
	t_room	*tmp;
	t_link	*ptr;
	
	tmp = NULL;
	if (new_room->in == 1)
	{
		new_room->links = 1;
		tmp = find_room_by_name_inout(new_farm, new_room->name, 0, 1);
		add_link(new_room, tmp);
		return;
	}
	ptr = room->link;
	new_room->links = room->links;
	while (ptr)
	{
		tmp = find_room_by_name_inout(new_farm, ptr->room->name, 1, 0);
		if (!tmp)
			tmp = find_room_by_name_inout(new_farm, ptr->room->name, 0, 0);
		if (!tmp)
			terminate(-1);
		add_link(new_room, tmp);
		ptr = ptr->next;
	}
}

void	make_links(t_farm *new_farm, t_farm *farm)
{
	t_room	*ptr;
	t_room	*tmp;

	ptr = farm->room;
	while (ptr)
	{
		if (ptr == farm->start)
			tmp = find_room_by_name_inout(new_farm, ptr->name, 0, 0);
		else if (ptr == farm->end)
			tmp = find_room_by_name_inout(new_farm, ptr->name, 0, 0);
		else
			tmp = find_room_by_name_inout(new_farm, ptr->name, 1, 0);
		if (tmp == NULL)
			terminate(-1);
		copy_links(new_farm, tmp, ptr);
		if (tmp->in == 1)
			copy_links(new_farm, find_room_by_name_inout(new_farm, ptr->name, 0, 1), ptr);
		ptr = ptr->next;
	}
}
