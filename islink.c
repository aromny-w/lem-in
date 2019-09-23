/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:48:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/23 18:19:24 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		isdupelink(t_room *room, char *name1, char *name2)
{
	if (room)
	{
		while (ft_strcmp(name1, room->name))
			room = room->next;
		while (room->link)
		{
			if (!ft_strcmp(name2, room->link->room->name))
				return (1);
			room->link = room->link->next;
		}
	}
	return (0);
}

static int		isexist(t_room *room, char *name)
{
	while (room && ft_strcmp(name, room->name))
		room = room->next;
	if (room)
		return (1);
	return (0);
}

static size_t	namelen2(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line != '-')
		line++;
	if (!*line++)
		return (0);
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

static size_t	namelen1(char *line)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

int				islink(char *line, t_room *room)
{
	char	name1[1 + namelen1(line)];
	char	name2[1 + namelen2(line)];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_isalnum(*line) || *line == '_')
		name1[i++] = *line++;
	name1[i] = '\0';
	if (*line++ != '-')
		return (0);
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		name2[j++] = *line++;
	name2[j] = '\0';
	if (!isexist((room), name1) || !isexist(room, name2))
		return (0);
	if (isdupelink(room, name1, name2))
		return (0);
	if (!*line)
		return (1);
	return (0);
}
