/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:44:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/20 17:50:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "t_rooms_queue.h"

void	print_queue(t_rooms_queue *queue)
{
	t_rooms_queue *ptr;

	ptr = queue;

	ft_printf("Debug queue: ");
	while (ptr)
	{	
		if (ptr->room)
			ft_printf("%s ", ptr->room->name);
		ptr = ptr->next;
	}
	ft_printf("\n");
	return ;
}
