/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:29:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/07 11:50:27 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_rooms_count(t_farm *farm)
{
	int		i;
	t_room	*ptr;

	i = 0;
	ptr = farm->room;
	while (ptr)
	{
		ptr->visited = 0;
		ptr->excluded = 0;
		ptr->dist = 0;
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_room		*find_room_by_num(t_farm *farm, int num)
{
	t_room		*ptr;

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

t_room		*find_room_by_name_inout(t_farm *farm, char *name, int in, int out)
{
	t_room		*ptr;

	ptr = farm->room;
	while (ptr)
	{
		if (!ft_strcmp(ptr->name, name) && ptr->in == in && ptr->out == out)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void		debug_print_rooms(t_farm *farm)
{
	t_room	*ptr;
	t_link	*lptr;

	ptr = farm->room;
	while (ptr)
	{
		ft_printf("ROOM %s: \n", ptr->name);
		lptr = ptr->link;
		while (lptr)
		{
			ft_printf("%s (%d %d) | ", lptr->room->name, lptr->room->in, lptr->room->out);
			lptr = lptr->next;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
	ft_printf("))))))))))\n");
}

void		reset_dist(t_farm *farm)
{
	t_room	*ptr;

	ptr = farm->room;
	while (ptr)
	{
		ptr->dist = 0;
		ptr->visited = 0;
		ptr = ptr->next;
	}
}
