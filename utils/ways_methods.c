/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 06:23:23 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 15:12:51 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways	*get_next_ways(t_ways *ways)
{
	t_ways *ptr;

	ptr = ways;
	if (!ptr)
		return (init_ways());
	if (ptr && ptr->way)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = init_ways();
		ptr = ptr->next;
	}
	return (ptr);
}

void	get_next_shortest(int *dist_num[2], t_room *room, t_farm *farm)
{
	t_link	*ptr;
	
	ptr = room->link;
	(void)farm;
	while (ptr)
	{
		if (!(ptr->room->excluded) && ((*dist_num)[0] - ptr->room->dist == 1))
		{
			(*dist_num)[0] = ptr->room->dist;
			(*dist_num)[1] = ptr->room->num;
		}
		ptr = ptr->next;
	}
}

void	add_new_way(t_ways *ways, int dist_num[2], t_farm *farm)
{
	t_room	*tmp;
	t_ways 	*new_ways;
	t_way	*new_way;
	t_way	*way_begin;	

	new_ways = get_next_ways(ways);
	ft_printf("%d DIST\n", dist_num[0]);
	new_ways->dist = dist_num[0];
	tmp = find_room_by_num(farm, dist_num[1]);
	tmp->excluded = 1;
	new_way = init_way(tmp);
	way_begin = new_way;
	ft_printf("Shortest name %s\n", tmp->name);
	while (1)
	{
		get_next_shortest(&dist_num, tmp, farm);
		ft_printf("shortest %d\n", dist_num[1]);
		tmp = find_room_by_num(farm, dist_num[1]);
		ft_printf("Shortest name %s\n", tmp->name);
		if (tmp == farm->start || tmp == farm->end)
			break;
		tmp->excluded = 1;
		new_way->next = init_way(tmp);
		new_way = new_way->next;
	}
	print_way(way_begin);
	new_ways->way = way_begin;
}

int		add_way(t_ways *ways, t_farm *farm)
{
	t_link	*ptr;
	int		dist_num[2];
	
	debug_print_rooms(farm);
	dist_num[0] = -1;
	ptr = farm->start->link;
	while (ptr)
	{
		if (ptr->room->dist && !ptr->room->excluded &&
			(dist_num[0] == -1 || dist_num[0] > ptr->room->dist))
		{
			dist_num[0] = ptr->room->dist;
			dist_num[1] = ptr->room->num;
		}
		ptr = ptr->next;
	}
	ft_printf("shortest %d %d\n", dist_num[1], dist_num[0]);
	if (dist_num[0] == -1)
		return (0);
	add_new_way(ways, dist_num, farm);
	return (1);
}
