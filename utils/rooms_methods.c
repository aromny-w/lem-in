/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:39:08 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/26 16:40:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_has_link(t_room *room, t_room *dest)
{
	t_link	*ptr;

	ptr = room->link;
	while (ptr)
	{
		if (ptr->room == dest)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
