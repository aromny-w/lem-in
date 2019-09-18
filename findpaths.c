/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpaths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:22:07 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/14 21:22:08 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*getbestlink(t_link *link)
{
	t_room	*best;

	best = link->room;
	while (link)
	{
		if (link->room->dist < best->dist)
			best = link->room;
		link = link->next;
	}
	return (best);
}

static void		setnewpath(t_farm farm, t_path *path)
{
	t_way	*way;
	size_t	len;

	len = 0;
	way = waynew(farm.end);
	while (way->room != farm.start)
	{
		wayadd(&way, waynew(getbestlink(way->room->link)));
		len++;
	}
	path->way = way;
	path->len = len;
}

static void		reverse_paths(t_farm *farm, t_path *init, size_t k)
{
	t_way	*tmp;
	size_t	i;

	i = -1;
	if (!init)
		return ;
	while (++i < k)
	{
		tmp = init[i].way;
		while (tmp->next)
		{
			while (tmp->room->link->room != tmp->next->room)
				tmp->room->link = tmp->room->link->next;
			tmp->room->link->weight = INFINITY;
			tmp = tmp->next;
		}
	}
}

t_path			*findpaths(t_farm farm, t_path *path, t_path *init, size_t k)
{
	size_t	i;

	i = 0;
	reverse_paths(&farm, init, k - 1);
//	set_distance(&farm.start, 0);
	if (!farm.end->links)
		return (NULL);
//	setnewpath(farm, path[k - 1]);
	setpath(farm, &path[k - 1], pathnew(NULL, 0), farm.start);
	if (path[k - 1].way)
		wayrev(&path[k - 1].way);
	return (path);
}
