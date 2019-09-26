/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/26 17:45:20 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	abortreading(int fd, char **line)
{
	close(fd);
	free(*line);
	terminate(-1);
}

static void	datarev(t_farm *farm)
{
	t_room	*tmp;

	roomrev(&farm->room);
	tmp = farm->room;
	while (tmp)
	{
		linkrev(&tmp->link);
		tmp = tmp->next;
	}
}

static int	readcommand(t_farm *farm, int fd, char **line)
{
	char	cmd[ft_strlen(*line) + 1];

	ft_strcpy(cmd, *line);
	if (ft_strcmp("##start", cmd) && ft_strcmp("##end", cmd))
		return (0);
	free(*line);
	get_next_line(fd, line);
	if (!ft_strcmp("##start", cmd) && isroom(*line, farm->room))
	{
		setroom(*line, &farm->start);
		roomadd(&farm->room, farm->start);
	}
	else if (!ft_strcmp("##end", cmd) && isroom(*line, farm->room))
	{
		setroom(*line, &farm->end);
		roomadd(&farm->room, farm->end);
	}
	else
		return (0);
	return (1);
}

void		readinput(t_farm *farm, int fd, char *line)
{
	int	s[3];

	s[0] = 0;
	s[1] = 0;
	s[2] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (isantnbr(line) && farm->ants < 0 && !s[1] && !s[2] && (s[0] = 1))
			farm->ants = ft_getnbr(line);
		else if (isroom(line, farm->room) && s[0] && !s[2] && (s[1] = 1))
			setroom(line, &farm->room);
		else if (islink(line, farm->room) && s[0] && s[1] && (s[2] = 1))
			setlink(line, farm);
		else if (iscomment(line))
			continue ;
		else if (iscommand(line))
			readcommand(farm, fd, &line) ? s[1] = 1 : 0;
		else
			abortreading(fd, &line);
		free(line);
	}
	datarev(farm);
	close(fd);
}
