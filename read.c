/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 15:38:14 by aromny-w         ###   ########.fr       */
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
		if (isantnbr(line) && farm->ants < 0 && (s[0] = 1 && !s[1] && !s[2]))
			farm->ants = ft_getnbr(line);
		else if (isroom(line, farm->room) && (s[1] = 1 && s[0] && !s[2]))
			setroom(line, &farm->room);
		else if (islink(line, farm->room) && (s[2] = 1) && s[0] && s[1])
			setlink(line, farm);
		else if (line[0] == '#' && line[1] != '#')
			continue ;
		else if (readcmd(farm, fd, line, &line))
			s[1] = 1;
		else
			break ;
	}
	close(fd);
	if (!s[0] || !s[1] || !s[2])
		terminate(-1);
}
