/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancelpaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:31:29 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/01 18:47:48 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	isinvalid(t_way *way)
{
	t_way	*tmp;
	t_link	*link;

	tmp = way;
	while (tmp)
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

void	cancelpaths(t_path *path, size_t k)
{
	size_t	i;
	//size_t	j;

	i = -1;
	while (++i < k)
	{
		if (isinvalid(path[i].way))
		{
			path[i].way = NULL;
			path[i].len = 0;
		}
	}
}
