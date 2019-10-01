/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoverlap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:31:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/01 20:44:47 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	fixoverlap(t_way *init, t_room *src, t_room *dst)
{
	t_way	*tmp;
	t_link	*link;

	tmp = init;
	while (tmp && tmp->room != src)
		tmp = tmp->next;
	if (!tmp || !tmp->next)
		return (0);
	link = tmp->room->link;
	while (link && link->room != dst)
		link = link->next;
	if (link)
		link->weight = INFINITY;
	else
		return (0);
	return (1);
}

int			checkoverlap(t_path new, t_path *init, size_t k)
{
	t_way	*tmp;
	size_t	i;
	int		exist;

	exist = 0;
	tmp = new.way;
	while (tmp)
	{
		i = 0;
		while (i < k - 1 && tmp->next)
			if (fixoverlap(init[i++].way, tmp->next->room, tmp->room))
				exist = 1;
		tmp = tmp->next;
	}
	return (exist);
}
