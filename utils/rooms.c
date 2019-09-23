/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:29:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 09:36:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_rooms_count(t_farm *farm)
{
	int	i;
	t_room *ptr;

	i = 0;
	if (farm->start)
	{
		farm->start->num = i;
		farm->start->visited = 0;
		farm->start->dist = 0;
		farm->start->excluded = 0;
		i++;
		ft_printf("%s %d\n", farm->start->name, farm->start->num);
	}
	ptr = farm->room;
	while (ptr)
	{
		ptr->num = i;
		i++;
		ptr->visited = 0;
		ptr->excluded = 0;
		ptr->dist = 0;
		ft_printf("%s %d\n", ptr->name, ptr->num);
		ptr = ptr->next;
	}
	if (farm->end)
	{
		farm->end->num = i;
		farm->end->visited = 0;
		farm->end->dist = 0;
		farm->end->excluded = 0;
		i++;
		ft_printf("%s %d\n", farm->end->name, farm->end->num);
	}
	return (i);
}

t_room		*find_room_by_num(t_farm *farm, int num)
{
	t_room *ptr;
	
	if (farm->start->num == num)
		return (farm->start);
	if (farm->end->num == num)
		return (farm->end);
	ptr = farm->room;
	while (ptr)
	{
		if (ptr->num == num)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void		debug_print_rooms(t_farm *farm)
{
	t_room *ptr;

	ft_printf("START: %s %d %d %d %d\n",
		farm->start->name, farm->start->num,
		farm->start->dist, farm->start->excluded,
		farm->start->visited);
	ft_printf("END: %s %d %d %d %d\n",
		farm->end->name, farm->end->num,
		farm->end->dist, farm->end->excluded,
		farm->end->visited);
	ptr = farm->room;
	while (ptr)
	{
		ft_printf("LINK: %s %d %d %d %d\n",
			ptr->name, ptr->num,
			ptr->dist, ptr->excluded,
			ptr->visited);
		ptr = ptr->next;
	}
}

void	reset_dist(t_farm *farm)
{
	t_room	*ptr;
	
	ptr = farm->room; 
	while (ptr)
	{
		if (!ptr->excluded)
		{
			ptr->dist = 0;
			ptr->visited = 0;
		}
		ptr = ptr->next;
	}
}
