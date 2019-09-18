/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setroom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:24 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/06 16:58:31 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	setroom(char *line, t_room **room)
{
	t_room	*tmp;

	if (!*room)
		*room = roomnew(line);
	else
	{
		tmp = *room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = roomnew(line);
	}
}*/

void	setroom(char *line, t_room **room)
{
	t_room	*tmp;

	tmp = roomnew(line);
	tmp->next = *room;
	*room = tmp;
}
