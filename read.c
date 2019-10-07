/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/07 13:45:29 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	abortreading(int fd, char **line, char **out, t_farm *farm)
{
	close(fd);
	if (out && *out)
		free(*out);
	if (line && *line)
		free(*line);
	destroyfarm(farm);
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

static int	readcommand(t_farm *farm, int fd, char **line, char **out)
{
	char	cmd[ft_strlen(*line) + 1];

	ft_strcpy(cmd, *line);
	if (ft_strcmp("##start", cmd) && ft_strcmp("##end", cmd))
		return (0);
	free(*line);
	if (!get_next_line(fd, line))
		abortreading(fd, NULL, out, farm);
	if (!ft_strcmp("##start", cmd) && line && isroom(*line, farm->room))
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
		abortreading(fd, line, out, farm);
	return (1);
}

void		readinput(t_farm *farm, int fd, char *line, char **out)
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
			;
		else if (iscommand(line))
			readcommand(farm, fd, &line, out) ? s[1] = 1 : 0;
		else
			abortreading(fd, &line, out, farm);
		*out = ft_concat(*out, line);
		if (line)
			free(line);
	}
	datarev(farm);
	close(fd);
}
