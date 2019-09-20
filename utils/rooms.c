/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:29:48 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 01:35:13 by bharrold         ###   ########.fr       */
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
		i++;
	}
	ptr = farm->room;
	while (ptr)
	{
		ptr->num = i;
		i++;
		ptr = ptr->next;
	}
	if (farm->end)
	{
		farm->end->num = i;
		i++;
	}
	return (i);
}
