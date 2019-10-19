/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjustlinks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:57:27 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/07 11:29:07 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	adjustroomlinks(t_link **link, t_room *end)
{
	t_link	*tmp;
	t_link	*new;
	t_link	*del;

	new = NULL;
	tmp = *link;
	if (tmp->room->in)
		linkadd(&new, linknew(tmp->room->link->room, INFINITY));
	while (tmp->next)
	{
		if (tmp->next->room->in || tmp->next->room == end)
		{
			del = tmp->next;
			if (tmp->next->room->in)
				linkadd(&new, linknew(tmp->next->room->link->room, INFINITY));
			tmp->next = tmp->next->next;
			free(del);
		}
		else
			tmp = tmp->next;
	}
	(void)end;
	(void)del;
	linkrev(&new);
	tmp->next = new;
}

static void	adjustendlinks(t_link **link, t_room *start)
{
	t_link	*tmp;
	t_link	*new;

	new = NULL;
	tmp = *link;
	if (tmp->room->in)
		linkadd(&new, linknew(tmp->room->link->room, INFINITY));
	else if (tmp->room == start)
		linkadd(&new, linknew(tmp->room, INFINITY));
	while (tmp->next)
	{
		if (tmp->next->room->in)
			linkadd(&new, linknew(tmp->next->room->link->room, INFINITY));
		else if (tmp->next->room == start)
			linkadd(&new, linknew(tmp->next->room, INFINITY));
		tmp = tmp->next;
	}
	(void)start;
	linkrev(&new);
	linkdel(link);
	*link = new;
}

static void	adjuststartlinks(t_link **link)
{
	return ((void)link);
}

void		adjustlinks(t_room **room, t_room *start, t_room *end)
{
	t_room	*tmp;

	tmp = *room;
	while (tmp)
	{
		if (tmp->link && tmp == start)
			adjuststartlinks(&tmp->link);
		else if (tmp->link && tmp == end)
			adjustendlinks(&tmp->link, start);
		else if (tmp->in && tmp->link)
			adjustroomlinks(&tmp->link, end);
		tmp = tmp->next;
	}
}
