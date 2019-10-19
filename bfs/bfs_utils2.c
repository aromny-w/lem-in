/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:07:07 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 13:07:18 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		lenway(t_way *way)
{
	t_way	*ptr;
	int		i;

	i  = 0;
	ptr = way;
	while (ptr)
	{
		i++;
		ptr->ant = 0;
		ptr = ptr->next;
	}
	return (i);
}

void	push_to_ways(t_ways ***ways, t_way *way, int num, t_farm *farm)
{
	t_ways *ptr;
	
	farm->real_variations = num;
	farm->ways_variations_cnt[num] += 1;
	if (!(*ways)[num])
	{
		(*ways)[num] = init_ways();
		(*ways)[num]->way = way;
		(*ways)[num]->next = NULL;
		(*ways)[num]->dist = 0;
		(*ways)[num]->dist = lenway(way);
		return ;
	}
	else
	{
		ptr = (*ways)[num];
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = init_ways();
		ptr->next->way = way;
		ptr->next->dist = lenway(way);
	}
}


t_way	*normal_way(t_way *way)
{
	t_way	*ptr;
	t_way	*cur;

	ptr = way;
	cur = NULL;
	cur = ptr;
	ptr = ptr->next;
	way = way->next;
	free(cur);
	while (ptr && ptr->next)
	{
		if (ptr->room->name == ptr->next->room->name)
		{
			cur = ptr->next;
			ptr->next = ptr->next->next;
			free(cur);
			continue;
		}
		ptr = ptr->next;
	}
	return (way);
}
