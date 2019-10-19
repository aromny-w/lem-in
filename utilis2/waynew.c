/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waynew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:47:34 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/07 20:58:49 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*waynew(t_room *room)
{
	t_way	*way;

	way = NULL;
	if (!(way = (t_way *)malloc(sizeof(t_way))))
		terminate(-1);
	way->room = room;
	way->next = NULL;
	return (way);
}
