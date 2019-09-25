/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:22:07 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 19:32:08 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		reverselink(t_room **room1, t_room **room2)
{
	t_link	*link1;
	t_link	*link2;

	link1 = (*room1)->link;
	link2 = (*room2)->link;
	while (link1->room != *room2)
		link1 = link1->next;
	link1->weight = INFINITY;
	while (link2->room != *room1)
		link2 = link2->next;
	link2->weight = -1;
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
	size_t	i;

	i = 0;
	reversepaths(init, k - 1);
	if (!farm.end->links)
		return (NULL);
	dfs(farm, &path[k - 1], pathnew(NULL, 0), farm.start);
	if (path[k - 1].way)
		wayrev(&path[k - 1].way);
	return (path);
}
