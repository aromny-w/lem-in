/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:22:07 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 15:52:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		reverse_paths(t_farm *farm, t_path *init, size_t k)
{
	t_way	*tmp;
	size_t	i;

	(void)farm;
	i = -1;
	if (!init)
		return ;
	while (++i < k)
	{
		tmp = init[i].way;
		while (tmp)
		{
			while (tmp->room->link->room != tmp->next->room)
				tmp->room->link = tmp->room->link->next;
			tmp->room->link->weight = INFINITY;
			tmp = tmp->next;
		}
	}
}

t_path			*find_paths(t_farm farm, t_path *path, t_path *init, size_t k)
{
	size_t	i;

	i = 0;
	reverse_paths(&farm, init, k - 1);
//	set_distance(&farm.start, 0);
	if (!farm.end->links)
		return (NULL);
//	setnewpath(farm, path[k - 1]);
	setpath(farm, &path[k - 1], pathnew(waynew(NULL), 0), farm.start);
	return (path);
}
