/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:22:07 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/22 21:52:24 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initdistance(t_room **room)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		tmp->dist = INFINITY;
		tmp = tmp->next;
	}
}

static size_t	addpath(t_path *path, t_path new, size_t k)
{
	size_t	i;

	i = 0;
	if (path)
		while (i < k - 1 && path[i].way)
			i++;
	path[i].way = new.way;
	path[i].len = new.len;
	sortpaths(path, k);
	return (++i);
}

static void		reverselink(t_room **room1, t_room **room2)
{
	t_link	*link1;
	t_link	*link2;

	link1 = (*room1)->link;
	link2 = (*room2)->link;
	while (link1->room != *room2)
		link1 = link1->next;
	if ((*room1)->name == (*room2)->name)
		link1->weight = link1->weight == 0 ? INFINITY : 0;
	else
		link1->weight = link1->weight == 1 ? INFINITY : 1;
	while (link2->room != *room1)
		link2 = link2->next;
	if ((*room1)->name == (*room2)->name)
		link2->weight = link2->weight == INFINITY ? 0 : INFINITY;
	else
		link2->weight = link2->weight == INFINITY ? 1 : INFINITY;
}

static void		reversepaths(t_path *init, t_path new, size_t k)
{
	t_way	*tmp;
	size_t	i;

	i = -1;
	if (!init)
		return ;
	while (++i < k)
	{
		tmp = init[i].way;
		while (tmp && tmp->next && tmp != new.way)
		{
			reverselink(&tmp->room, &tmp->next->room);
			tmp = tmp->next;
		}
	}
}

t_path			*findpaths(t_farm farm, t_path *path, size_t k)
{
	t_path	new;

	new = pathnew(NULL, 0);
	initdistance(&farm.room);
	reversepaths(path, new, k - 1);
	dfs(farm, &new, pathnew(NULL, 0), farm.start);
	reversepaths(path, new, k - 1);
	if (new.way)
		;//wayrev(&new.way);
	else
		return (NULL);
	if (checkoverlap(new))
	{
		cancelpaths(path, new, k);
		return (findpaths(farm, path, k));
	}
	else if (addpath(path, new, k) < k)
		return (findpaths(farm, path, k));
	return (path);
}
