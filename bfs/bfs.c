/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:26:34 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/20 17:57:52 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "t_rooms_queue.h"


// t_path		algo_bgs(t_rooms_queue *queue, t_farm *farm, t_path *path)
// {
// 	if (peek(queue) == farm->end)
// 	{
// 		return ();
// 	}
// }

t_path		*bfs (t_farm *farm)
{
	t_rooms_queue	*queue;
	
	queue = NULL;
	ft_printf("%s\n", farm->start->name);
	enqueue(&queue, farm->start);
	enqueue(&queue, farm->start->link->room);
	//print_queue(queue);
	return (NULL);
}
