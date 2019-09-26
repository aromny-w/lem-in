/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:35:27 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 00:01:47 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*roomnew(char *name, t_point coords, t_link *link)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		terminate(-1);
	room->name = name;
	room->coords = coords;
	room->dist = INFINITY;
	room->visited = 0;
	room->excluded = 0;
	room->num = 0;
	room->in = 0;
	room->out = 0;
	room->links = 0;
	room->link = link;
	room->next = NULL;
	return (room);
}
