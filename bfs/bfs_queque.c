/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:33:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/19 15:00:18 by bharrold         ###   ########.fr       */
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
	t_room	*result;
	t_rooms_queue	*next;

	result = NULL;
	result = NULL;
	if (!queue)
		return (NULL);
	result = queue->room;
	if (queue->prev && queue->next)
	{
		queue->prev->next = queue->next;
		queue->next->prev = queue->prev;
		next= queue->prev;
	}
	else if (queue->prev)
	{
		queue->prev->next = NULL;
		next=queue->prev;
	}	
	else if (queue->next)
	{
		queue->next->prev = NULL;
		next = queue->next;
	}
	else
		next = NULL;
	free(queue);
	queue = next;
	return (result);
}

t_room *peek(t_rooms_queue *queue)
{
	if (queue)
		return (queue->room);
	return (NULL);
}

int count(t_rooms_queue *queue)
{
	int				i;
	t_rooms_queue	*ptr;

	i = 0;
	ptr = queue;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void		destroy_queue(t_rooms_queue *queue)
{
	t_rooms_queue *ptr;
	t_rooms_queue *current;

	ptr = queue;
	while (ptr->prev)
		ptr = ptr->prev;
	while (ptr)
	{
		current = ptr;
		ptr = ptr->next;
		free(current);
	}
}
