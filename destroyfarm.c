/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyfarm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:23:40 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 17:24:50 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	del(void *elem, size_t size)
{
	size = 0;
	free(elem);
}

static void	destroylinks(t_link **link)
{
	t_link	*tmp;
	t_link	*next;

	tmp = *link;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void		destroyfarm(t_farm *farm)
{
	t_room	*tmp;
	t_room	*next;

	tmp = farm->room;
	while (tmp)
	{
		next = tmp->next;
		destroylinks(&tmp->link);
		if (!tmp->in)
			free(tmp->name);
		free(tmp);
		tmp = next;
	}
	ft_lstdel(&farm->buf, del);
	ft_memset(farm, 0, sizeof(t_farm));
	farm = NULL;
}

void		destroyfarmways(t_farm *farm, t_ways *ways)
{
	destroyfarm(farm);
	destroy_ways(ways);
	exit(-1);
}
