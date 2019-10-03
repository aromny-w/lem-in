/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:22:07 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/03 22:50:29 by aromny-w         ###   ########.fr       */
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

static size_t	mergepaths(t_path *path, t_path *init, t_path new, size_t k)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (init)
		while (++i < k - 1)
		{
			if (init[i].way)
			{
				path[j].way = init[i].way;
				path[j].len = init[i].len;
				j++;
			}
		}
	path[j].way = new.way;
	path[j].len = new.len;
	if (new.way)
		j++;
	return (j);
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

static void		reversepaths(t_path *init, size_t k)
{
	t_way	*tmp;
	size_t	i;

	i = -1;
	if (!init)
		return ;
	while (++i < k)
	{
		tmp = init[i].way;
		while (tmp && tmp->next)
		{
			reverselink(&tmp->room, &tmp->next->room);
			tmp = tmp->next;
		}
	}
}

t_path			*findpaths(t_farm farm, t_path *path, t_path *init, size_t k)
{
	t_path	new;
	size_t	i;

	new = pathnew(NULL, 0);
	i = mergepaths(path, init, new, k);
	initdistance(&farm.room);
	reversepaths(init, k - 1);
	dfs(farm, &new, pathnew(NULL, 0), farm.start);
	reversepaths(init, k - 1);
	if (new.way)
		wayrev(&new.way);
	else
		return (NULL);
	if (checkoverlap(new, init, k))
	{
		cancelpaths(path, k);
		return (findpaths(farm, path, path, k));
	}
	else
		i = mergepaths(path, init, new, k);
	if (i < k)
		return (findpaths(farm, path, path, k));
	return (path);
}
