/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:35:27 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 01:40:44 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	setcoords(char *line, t_point *coords)
{
	while (*line != ' ')
		line++;
	coords->x = ft_atoi(++line);
	while (*line != ' ')
		line++;
	coords->y = ft_atoi(++line);
}

static char	*getroomname(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != ' ')
		len++;
	return (ft_strsub(line, 0, len));
}

t_room		*roomnew(char *line)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		terminate(-1);
	room->name = getroomname(line);
	setcoords(line, &room->coords);
	room->dist = INFINITY;
	room->links = 0;
	room->link = NULL;
	room->next = NULL;
	return (room);
}
