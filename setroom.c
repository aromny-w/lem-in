/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setroom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:58:24 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 15:36:39 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_point	getcoords(char *line)
{
	t_point	coords;

	while (*line != ' ')
		line++;
	coords.x = ft_getnbr(++line);
	while (*line != ' ')
		line++;
	coords.y = ft_getnbr(++line);
	return (coords);
}

static char		*getroomname(char *line)
{
	size_t	len;

	len = 0;
	while (line[len] != ' ')
		len++;
	return (ft_strsub(line, 0, len));
}

void			setroom(char *line, t_room **room)
{
	roomadd(room, roomnew(getroomname(line), getcoords(line), NULL));
}
