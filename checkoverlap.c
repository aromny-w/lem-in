/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoverlap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:31:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/03 23:19:43 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	collapselink(t_room **src, t_room **dst)
{
	t_link	*tmp;

	tmp = (*src)->link;
	while (tmp)
	{
		if (tmp->room == *dst)
		{
			tmp->weight = INFINITY;
			break ;
		}
		tmp = tmp->next;
	}
	return (1);
}

int			checkoverlap(t_path new)
{
	t_way	*tmp;
	int		check;

	check = 0;
	tmp = new.way;
	while (tmp && tmp->next)
	{
		if (tmp->room->name != tmp->next->room->name)
			if (tmp->room->in == 1 && tmp->next->room->out == 1)
				check = collapselink(&tmp->next->room, &tmp->room);
		tmp = tmp->next;
	}
	return (check);
}
