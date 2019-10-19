/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/19 17:26:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	abortreading(t_farm *farm, int fd, char **line)
{
	close(fd);
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
	ft_lstrev(&farm->buf);
}

int	readcommand(t_farm *farm, int fd, char **line)
{
	char	cmd[ft_strlen(*line) + 1];

	ft_strcpy(cmd, *line);
	if (ft_strcmp("##start", cmd) && ft_strcmp("##end", cmd))
		return (0);
	ft_lstadd(&farm->buf, ft_lstnew(*line, ft_strlen(*line) + 1));
	free(*line);
	if (get_next_line(fd, line) != 1)
		*line = ft_strdup("");
	if (!isroom(*line, farm->room))
		abortreading(farm, fd, line);
	else if (!ft_strcmp("##start", cmd))
	{
		setroom(*line, &farm->start);
		roomadd(&farm->room, farm->start);
	}
	else if (!ft_strcmp("##end", cmd))
	{
		setroom(*line, &farm->end);
		roomadd(&farm->room, farm->end);
	}
	return (1);
}

void		readinput(t_farm *farm, int fd, char *line)
{
	int		s[3];

	ft_memset(s, 0, sizeof(s));
	while (get_next_line(fd, &line) == 1)
	{
		if (isantnbr(line) && farm->ants < 0 && !s[1] && !s[2] && (s[0] = 1))
			farm->ants = ft_getnbr(line);
		else if (isroom(line, farm->room) && s[0] && !s[2] && (s[1] = 1))
			setroom(line, &farm->room);
		else if (islink(line, farm->room) && s[0] && s[1] && (s[2] = 1))
			setlink(line, farm);
		else if (iscomment(line))
			(void)line;
		else if (iscommand(line))
			readcommand(farm, fd, &line) ? s[1] = 1 : 0;
		else
			abortreading(farm, fd, &line);
		ft_lstadd(&farm->buf, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	datarev(farm);
	close(fd);
}
