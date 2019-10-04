/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:38:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/04 16:13:17 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	iscycle(t_way *way)
{
	t_way	*tmp;
	t_room	*room;

	return (0);
	tmp = way;
	room = tmp->room;
	while ((tmp = tmp->next))
		if (tmp->room == room)
			return (1);
	return (0);
}

void		dfs(t_farm farm, t_path *new, t_path tmp, t_room *room)
{
	t_link	*link;

	wayadd(&tmp.way, waynew(room));
	tmp.len++;
	if (!room || iscycle(tmp.way) || (new->way && new->len < tmp.len) || tmp.len > room->dist)
		return ;
	else if (tmp.way->room == farm.end && (!new->way || tmp.len < new->len))
	{
		room->dist = tmp.len;
		*new = pathnew(tmp.way, tmp.len);
		return ;
	}
	room->dist = tmp.len;
	link = tmp.way->room->link;
	while (link)
	{
		if (link->weight != INFINITY)
			dfs(farm, new, tmp, link->room);
		link = link->next;
	}
}
