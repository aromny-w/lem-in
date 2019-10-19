/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:08:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/07 05:00:22 by bharrold         ###   ########.fr       */
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
	t_way	*ptr;
	t_way	*next;

	ptr = way;
	while (ptr)
	{
		next = ptr->next;
		free(ptr);
		ptr = NULL;
		ptr = next;
	}
}

t_ways	*init_ways(void)
{
	t_ways *ways;

	ways = (t_ways*)malloc(sizeof(t_ways));
	ways->way = NULL;
	ways->next = NULL;
	ways->dist = -1;
	return (ways);
}

void	destroy_ways(t_ways *ways)
{
	t_ways	*ptr;
	t_ways	*next;

	ptr = ways;
	while (ptr)
	{
		next = ptr->next;
		destroy_way(ptr->way);
		ptr->way = NULL;
		free(ptr);
		ptr = NULL;
		ptr = next;
	}
	ways = NULL;
}
