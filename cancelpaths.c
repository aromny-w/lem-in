/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancelpaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:44:17 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/20 20:07:01 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	shiftpaths(t_path *path, size_t k)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < k)
		if (path[i].way)
			path[++j] = path[i];
	while (++j < k)
		path[j] = pathnew(NULL, 0);
}

static int	isinvalid(t_way *way)
{
	t_way	*tmp;
	t_link	*link;

	tmp = way;
	while (tmp && tmp->next)
	{
		link = tmp->room->link;
		while (link->room != tmp->next->room)
			link = link->next;
		if (link->weight == INFINITY)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		cancelpaths(t_path *path, t_path new, size_t k)
{
	size_t	i;

	i = -1;
	(void)new;
	while (++i < k)
	{
		if (path[i].way && isinvalid(path[i].way))
		{
			path[i].way = NULL;
			path[i].len = 0;
		}
	}
	shiftpaths(path, k);
}
