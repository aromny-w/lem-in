/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:58:41 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/27 20:15:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	suurballe_exclude_link(t_farm *farm, int r1, int r2)
{
	t_room		*room;
	t_room		*room2;
	t_link		*ptr;

	room = find_room_by_num(farm, r1);
	room2 = find_room_by_num(farm, r2);
	ft_printf("EXCLUDE BETWEEN %s", room->name);
	if (room->in)
		ft_printf("(in) ");
	if (room->out)
		ft_printf("(out) ");
	ft_printf("%s", room2->name);
	if (room2->in)
		ft_printf("(in) ");
	if (room2->out)
		ft_printf("(out) ");
	ft_printf("\n");
	ptr = room->link;
	while (ptr)
	{
		if (ptr->room == room2)
			ptr->excluded = 1;
		ptr = ptr->next;
	}
}
