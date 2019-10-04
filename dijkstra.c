/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:04:46 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/04 16:28:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dijkstra_dist(t_farm *farm, t_room *start)
{
	t_room *ptr;
	
	ptr = farm->room;
	start->num = 0;
	int i = 1;
	while (ptr)
	{
		if (ptr == start)
			ptr->dist = 0;
		else
		{
			ptr->dist = INFINITY;
			ptr->num = i++;
		}
			
		ptr = ptr->next;
	}
}


void	algo_dijkstra(t_farm farm, t_path *new, t_path tmp, t_room *room)
{
	const int rooms_cnt = get_rooms_count(&farm);
	int visited[rooms_cnt];
	int i;

	i = -1;
	while (++i < rooms_cnt)
		visited[i] = 0;
	dijkstra_dist(&farm, room);
	ft_printf("rooms cnt %d\n", rooms_cnt);
	
	(void)new;
	(void)tmp;
	(void)room;
}
