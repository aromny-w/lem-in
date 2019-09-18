/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/04 18:15:10 by aromny-w         ###   ########.fr       */
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
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (!*line)
		return (1);
	return (0);
}

static int	isroom(char *line)
{
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

static int	isnumber(char *line)
{
	if (*line == '-' || *line == '+')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

static void	read_cmd(t_farm *farm, char *cmd, char *line)
{
	if (!ft_strcmp("##start", cmd) || !ft_strcmp("##end", cmd))
		get_next_line(0, &line);
	if (!ft_strcmp("##start", cmd) && isroom(line))
		farm->start = roomnew(line);
	if (!ft_strcmp("##end", cmd) && isroom(line))
		farm->end = roomnew(line);
}

void		readinput(t_farm *farm, char *line)
{
	while (get_next_line(0, &line) == 1)
	{
		if (isnumber(line) && !(farm->ants = 0))
			farm->ants = ft_getnbr(line);
		else if (line[0] == '#' && line[1] == '#')
			read_cmd(farm, line, NULL);
		else if (line[0] == 'L' || line[0] == '#')
			continue ;
		else if (isroom(line))
			setroom(line, &farm->room);
		else if (islink(line))
			setlink(line, farm);
		else
			break ;
	}
}
