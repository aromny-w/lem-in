/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_split_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:08:30 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/23 19:40:41 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*make_split_farm(t_farm *farm)
{
	t_farm	*new_farm;
	t_room	*ptr;

	new_farm = (t_farm*)malloc(sizeof(t_farm));
	new_farm->ants = farm->ants;
	ptr = farm->room;
	ft_printf("%p %s\n", farm->start, farm->start->name);
	ft_printf("%p %s\n", farm->end, farm->end->name);
	while (ptr)
	{
		ft_printf("%p\n", ptr);
		if (ptr == farm->start)
			ft_printf("Start: %s", ptr->name);
		else if (ptr == farm->end)
			ft_printf("End: %s", ptr->name);
		else
			ft_printf("ROOM %s\n", ptr->name);
		ptr = ptr->next;
	}
	
	return (new_farm);
}
