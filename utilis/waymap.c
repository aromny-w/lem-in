/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 11:43:52 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 14:04:36 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*waymap(t_way *way)
{
	t_way		*new;
	t_way		*new_ptr;

	new = waynew(way->room);
	new_ptr = way;
	while ((way = way->next))
	{
		if (!(new_ptr->next = waynew(way->room)))
		{
			waydel(&way);
			return (NULL);
		}
		new_ptr = new_ptr->next;
	}
	return (way);
}
