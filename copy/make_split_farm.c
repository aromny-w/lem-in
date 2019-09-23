/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_split_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:08:30 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/23 22:04:33 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_farm	*make_split_farm(t_farm *farm)
{
	t_farm	*new_farm;
	t_room	*ptr;
	t_link	*link_ptr;

	new_farm = (t_farm*)malloc(sizeof(t_farm));
	new_farm->room = NULL;
	new_farm->start = NULL;
	new_farm->end = NULL;
	new_farm->ants = farm->ants;
	copy_rooms(new_farm, farm);
	make_links(new_farm, farm);
	ptr = new_farm->room;
	while (ptr)
	{
		ft_printf("room\t%p\t%s\t%d\t%d\t%d\n", ptr, ptr->name, ptr->links, ptr->in, ptr->out);
		ft_printf("Links: ");
		link_ptr = ptr->link;
		while (link_ptr)
		{
			ft_printf("%s %d %d\t", link_ptr->room->name, link_ptr->room->in, link_ptr->room->out);
			link_ptr = link_ptr->next;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
	return (new_farm);
}
