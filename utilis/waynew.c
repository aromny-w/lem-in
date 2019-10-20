/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waynew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:47:34 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/14 21:47:34 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*waynew(t_room *room)
{
	t_way	*way;

	if (!(way = (t_way *)malloc(sizeof(t_way))))
		terminate(-1);
	way->room = room;
	way->next = NULL;
	return (way);
}
