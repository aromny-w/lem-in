/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linknew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:43:11 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/24 22:45:10 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*linknew(t_room *room, float weight)
{
	t_link *link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		terminate(-1);
	link->room = room;
	link->weight = weight;
	link->next = NULL;
	return (link);
}
