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

static int	isinteger(char *line)
{
	if (*line == '-' || *line == '+')
		line++;
	while (ft_isdigit(*line))
		line++;
	if (!*line)
		return (1);
	return (0);
}

static void	readcmd(t_farm *farm, char *cmd, char *line)
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
	int	ants;
	int rooms;
	int	links;

	ants = 0;
	rooms = 0;
	links = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (isinteger(line) && line[0] != '-' && (ants = 1 && !rooms && !links))
			farm->ants = ft_getnbr(line);
		else if (line[0] == '#' && line[1] == '#')
			readcmd(farm, line, NULL);
		else if (isroom(line) && (rooms = 1 && ants && !links))
			setroom(line, &farm->room);
		else if (islink(line) && (links = 1) && ants && rooms)
			setlink(line, farm);
		else if (line[0] == 'L' || line[0] == '#')
			continue ;
		else
			break ;
	}
}

/*void		readinput(t_farm *farm, char *aline)
{
	char	*line[21];
	size_t	i;

	i = -1;
	line[0] = "2";
	line[1] = "##start";;
	line[2] = "A 1 0";
	line[3] = "##end";
	line[4] = "H 5 0";
	line[5] = "B 4 2";
	line[6] = "C 9 0";
	line[7] = "D 13 0";
	line[8] = "E 13 0";
	line[9] = "F 2 5";
	line[10] = "G 2 4";
	line[11] = "A-B";
	line[12] = "A-E";
	line[13] = "B-C";
	line[14] = "C-D";
	line[15] = "D-E";
	line[16] = "D-F";
	line[17] = "E-F";
	line[18] = "F-G";
	line[19] = "D-H";
	line[20] = "G-H";
	while (++i < 21)
	{
		if (isnumber(line[i]) && !(farm->ants = 0))
			farm->ants = ft_getnbr(line[i]);
		else if (line[i][0] == '#' && line[i][1] == '#' && i++)
			readcmd(farm, line[i - 1], line[i]);
		else if (line[i][0] == 'L' || line[i][0] == '#')
			continue ;
		else if (isroom(line[i]))
			setroom(line[i], &farm->room);
		else if (islink(line[i]))
			setlink(line[i], farm);
		else
			break ;
	}
}*/
