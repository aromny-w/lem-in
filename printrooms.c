/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printrooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:38:59 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 20:14:16 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	printlinks(t_link *link)
{
	size_t	i;

	i = 0;
	while (link)
	{
		printf("%zu: %s %d %d - %3.f\n", ++i, link->room->name, link->room->in, 
		link->room->out, link->weight);
		link = link->next; 
	}
}

void	printrooms(t_room *room)
{
	while (room)
	{
		printf("%s %d %d:\n", room->name, room->in, room->out);
		printlinks(room->link);
		room = room->next;
	}
}
