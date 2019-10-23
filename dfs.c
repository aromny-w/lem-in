/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:38:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/23 23:50:06 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		*free_ways(t_path *tmp, void *ret)
{
	t_way *tmp_ptr;

	tmp_ptr = tmp->way;
	if (tmp->way && tmp->way->next)
		tmp->way = tmp->way->next;
	free(tmp_ptr);
	tmp_ptr = NULL;
	return (ret);
}

void		best_path(t_path **new, t_path *tmp)
{
	t_way	*ptr;
	t_way	*ptr_free;

	if (new && *new)
	{
		(*new)->len = 0;
		ptr = (*new)->way;
		while (ptr)
		{
			ptr_free = ptr;
			ptr = ptr->next;
			free(ptr_free);
			ptr_free = NULL;
		}
	}
	(**new) = pathnew(NULL, 0);
	ptr = tmp->way;
	while (ptr)
	{
		wayadd(&(*new)->way, waynew(ptr->room));
		ptr = ptr->next;
	}
	(*new)->len = tmp->len;
	(*new)->limit = 0;
}

void		*dfs(t_farm farm, t_path *new, t_path tmp, t_room *room)
{
	t_link	*link;

	wayadd(&tmp.way, waynew(room));
	tmp.len++;
	if (tmp.len > 200 || !room || (new->way && new->len < tmp.len) ||
		tmp.len > room->dist)
		return (free_ways(&tmp, NULL));
	else if (tmp.way->room == farm.end && (!new->way || tmp.len < new->len))
	{
		room->dist = tmp.len;
		best_path(&new, &tmp);
		return (free_ways(&tmp, NULL));
	}
	room->dist = tmp.len;
	link = tmp.way->room->link;
	while (link)
	{
		if (link->weight != INFINITY)
			dfs(farm, new, tmp, link->room);
		link = link->next;
	}
	return (free_ways(&tmp, NULL));
}
