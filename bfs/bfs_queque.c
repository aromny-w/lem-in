/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:33:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/18 18:44:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "t_rooms_queue.h"

void	*enqueue(t_rooms_queue *queue, t_room *room)
{
	t_rooms_queue	*prev;
	t_rooms_queue	*node;

	prev = queue;
	node = (t_rooms_queue*)malloc(sizeof(t_rooms_queue));
	node->room = room;
	node->visited = 0;
	node->prev = prev;
	node->next = NULL;
	return (node);
}

t_room	*dequeue(t_rooms_queue *queue)
{
	(void)queue;
	return (NULL);
}

t_room *peek(t_rooms_queue *queue)
{
	(void)queue;
	return (NULL);
}

int count(t_rooms_queue *queue)
{
	(void)queue;
	return (0);
}
