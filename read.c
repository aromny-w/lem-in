/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/23 22:26:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	readcmd(t_farm *farm, int fd, char *cmd, char **line)
{
	if (cmd[0] != '#' || cmd[1] != '#')
		return (0);
	if (!ft_strcmp("##start", cmd) || !ft_strcmp("##end", cmd))
		get_next_line(fd, line);
	if (!ft_strcmp("##start", cmd) && isroom(*line, farm->room))
	{
		(farm->start = roomnew(*line))->next = farm->room;
		farm->room = farm->start;
	}
	else if (!ft_strcmp("##end", cmd) && isroom(*line, farm->room))
	{
		(farm->end = roomnew(*line))->next = farm->room;
		farm->room = farm->end;
	}
	else
		return (0);
	return (1);
}

void		readinput(t_farm *farm, int fd, char *line)
{
	int	ants;
	int rooms;
	int	links;

	ants = 0;
	rooms = 0;
	links = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (isantnbr(line) && farm->ants < 0 && (ants = 1 && !rooms && !links))
			farm->ants = ft_getnbr(line);
		else if (readcmd(farm, fd, line, &line))
			rooms = 1;
		else if (isroom(line, farm->room) && (rooms = 1 && ants && !links))
			setroom(line, &farm->room);
		else if (islink(line, farm->room) && (links = 1) && ants && rooms)
			setlink(line, farm);
		else if (line[0] == '#')
			continue ;
		else
			break ;
		free(line);
	}
	close(fd);
	if (!ants || !rooms || !links)
		terminate(-1);
}
