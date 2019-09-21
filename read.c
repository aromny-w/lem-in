/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/20 18:03:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	islink(char *line)
{
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (*line == '-')
		line++;
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (!*line)
		return (1);
	return (0);
}

static int	isroom(char *line)
{
	int	name;
	int	x;
	int	y;

	name = 0;
	x = 0;
	y = 0;
	if (*line == 'L' || *line == '#')
		return (0);
	while ((ft_isalnum(*line) || *line == '_') && (name = 1))
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line) && (x = 1))
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line) && (y = 2))
		line++;
	if (!*line && (name && x && y))
		return (1);
	return (0);
}

static int	isantnbr(char *line)
{
	long	nbr;

	nbr = 0;
	if (!ft_isdigit(*line) && *line != '+')
		return (0);
	if (*line == '+')
		line++;
	while (ft_isdigit(*line) && nbr <= INT_MAX)
		nbr = 10 * nbr + (*line++ - '0');
	if (!*line && nbr <= INT_MAX)
		return (1);
	return (0);
}

static int	readcmd(t_farm *farm, char *cmd, char **line)
{
	if (!ft_strcmp("##start", cmd) || !ft_strcmp("##end", cmd))
		get_next_line(farm->fd, line);
	if (!ft_strcmp("##start", cmd) && isroom(*line))
		farm->start = roomnew(*line);
	else if (!ft_strcmp("##end", cmd) && isroom(*line))
		farm->end = roomnew(*line);
	else
		return (0);
	return (1);
}

void		readinput(t_farm *farm, char *line)
{
	int	ants;
	int rooms;
	int	links;

	ants = 0;
	rooms = 0;
	links = 0;
	while (get_next_line(farm->fd, &line) == 1)
	{
		if (isantnbr(line) && line[0] != '-' && (ants = 1 && !rooms && !links))
			farm->ants = ft_getnbr(line);
		else if (line[0] == '#' && line[1] == '#' && readcmd(farm, line, &line))
			rooms = 1;
		else if (isroom(line) && (rooms = 1 && ants && !links))
			setroom(line, &farm->room);
		else if (islink(line) && (links = 1) && ants && rooms)
			setlink(line, farm);
		else if (line[0] == '#')
			continue ;
		else
			break ;
	}
	close(farm->fd);
	if (!ants || !rooms || !links)
		terminate(-1);
}
