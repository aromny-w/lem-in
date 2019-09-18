/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setlink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:25:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/06 18:25:14 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link	*getlink(t_room *room)
{
	t_link	*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		terminate(-1);
	link->room = room;
	link->weight = 1;
	link->next = NULL;
	return (link);
}

static void	linker(t_room *room_1, t_room *room_2)
{
	t_link	*tmp_1;
	t_link	*tmp_2;
	
	if (!room_1 || !room_2)
		return ;
	tmp_1 = getlink(room_2);
	tmp_2 = getlink(room_1);
	tmp_1->next = room_1->link;
	tmp_2->next = room_2->link;
	room_1->link = tmp_1;
	room_2->link = tmp_2;
	room_1->links++;
	room_2->links++;
}

static t_room	*getroom_2(char *line, t_farm farm)
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

static t_room	*getroom_1(char *line, t_farm farm)
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

void		setlink(char *line, t_farm *farm)
{
	t_room	*room_1;
	t_room	*room_2;

	room_1 = getroom_1(line, *farm);
	room_2 = getroom_2(line, *farm);
	linker(room_1, room_2);
}
