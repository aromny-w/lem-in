/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:38:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 15:53:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	iscycle(t_way *way)
{
	t_way	*tmp;
	t_room	*room;

	tmp = way;
	room = tmp->room;
	while ((tmp = tmp->next))
		if (tmp->room == room)
			return (1);
	return (0);
}

void		setpath(t_farm farm, t_path *path, t_path tmp, t_room *room)
{
	t_link	*link;

	wayadd(&tmp.way, waynew(room));
	tmp.len++;
	if (!room || iscycle(tmp.way) || (path->way && path->len < tmp.len))
		return ;
	else if (tmp.way->room == farm.end && (!path->way || tmp.len < path->len))
	{
		*path = pathnew(tmp.way, tmp.len);
		// TODO reverse path
		return ;
	}
	link = tmp.way->room->link;
	while (link)
	{
		setpath(farm, path, tmp, link->room);
		link = link->next;
	}
}
