/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:25:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/24 22:54:34 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		linker(t_room *room_1, t_room *room_2)
{
	linkadd(&room_1->link, linknew(room_2, 1));
	linkadd(&room_2->link, linknew(room_1, 1));
	room_1->links++;
	room_2->links++;
}

static t_room	*getroom2(char *line, t_farm farm)
{
	char	*name;

	while (*line != '-')
		line++;
	name = ft_strdup(++line);
	if (farm.start && !ft_strcmp(name, farm.start->name))
		return (farm.start);
	if (farm.end && !ft_strcmp(name, farm.end->name))
		return (farm.end);
	while (farm.room && ft_strcmp(name, farm.room->name))
		farm.room = farm.room->next;
	return (farm.room);
}

static t_room	*getroom1(char *line, t_farm farm)
{
	char	*name;
	size_t	len;

	len = 0;
	while (line[len] != '-')
		len++;
	name = ft_strsub(line, 0, len);
	if (farm.start && !ft_strcmp(name, farm.start->name))
		return (farm.start);
	if (farm.end && !ft_strcmp(name, farm.end->name))
		return (farm.end);
	while (farm.room && ft_strcmp(name, farm.room->name))
		farm.room = farm.room->next;
	return (farm.room);
}

void			setlink(char *line, t_farm *farm)
{
	t_room	*room1;
	t_room	*room2;

	room1 = getroom1(line, *farm);
	room2 = getroom2(line, *farm);
	linker(room1, room2);
}
