/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyfarm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:23:40 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/23 23:49:19 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include "lem_in.h"

static void	del(void *elem, size_t size)
{
	size = 0;
	free(elem);
}

static void	destroy_rooms(t_room **room)
{
	t_room	*tmp;
	t_room	*next;

	tmp = *room;
	while (tmp)
	{
		next = tmp->next;
		linkdel(&tmp->link);
		if (tmp->in == 0)
			free(tmp->name);
		free(tmp);
		tmp = next;
	}
	*room = NULL;
}

void		destroyfarm(t_farm *farm)
{
	ft_lstdel(&farm->buf, del);
	destroy_rooms(&farm->room);
}
