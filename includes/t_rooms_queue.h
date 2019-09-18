/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rooms_queue.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:59:16 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/18 18:44:30 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ROOMS_QUEQUE_H
# define T_ROOMS_QUEQUE_H

#include "lem_in.h"

typedef struct				s_rooms_queue
{
	t_room					*room;
	int						visited;
	struct t_rooms_queue	*next;
	struct s_rooms_queue	*prev;
}							t_rooms_queue;

void						*enqueue(t_rooms_queue *queue, t_room *room);
t_room						*dequeue(t_rooms_queue *queue);
t_room						*peek(t_rooms_queue *queue);
int							count(t_rooms_queue *queue);

#endif
