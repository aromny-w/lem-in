/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:38:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/03 21:18:58 by aromny-w         ###   ########.fr       */
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

void		dfs(t_farm farm, t_path *new, t_path tmp, t_room *room)
{
	t_link	*link;

	wayadd(&tmp.way, waynew(room));
	tmp.len++;
	if (!room || iscycle(tmp.way) || (new->way && new->len < tmp.len))
		return ;
	else if (tmp.way->room == farm.end && (!new->way || tmp.len < new->len))
	{
		*new = pathnew(tmp.way, tmp.len);
		return ;
	}
	link = tmp.way->room->link;
	while (link)
	{
		if (link->weight != INFINITY)
			dfs(farm, new, tmp, link->room);
		link = link->next;
	}
}
