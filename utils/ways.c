/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:08:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 09:51:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*init_way(t_room *room)
{
	t_way	*way;
	
	way = (t_way*)malloc(sizeof(t_way));
	way->room = room;
	way->ant = 0;
	way->next = NULL;
	return (way);
}

void	destroy_way(t_way *way)
{
	t_way	*current;
	
	if (!way)
		return ;
	while (way)
	{
		current = way;
		way = way->next;
		free(way);
	}
}

t_ways	*init_ways(void)
{
	t_ways *ways;
	
	ways = (t_ways*)malloc(sizeof(t_ways));
	ways->way = NULL;
	ways->next = NULL;
	ways->dist = -1;
	return ways;
}

void	destroy_ways(t_ways *ways)
{
	t_ways	*current;
	
	if (!ways)
		return;
	while (ways)
	{
		current = ways;
		if (ways->way)
			destroy_way(ways->way);
		ways = ways->next;
		free(current);
	}
}
