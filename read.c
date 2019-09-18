/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 17:42:24 by bharrold         ###   ########.fr       */
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
//	if (!ft_strcmp("##start", cmd) || !ft_strcmp("##end", cmd))
//		get_next_line(0, &line);
	if (!ft_strcmp("##start", cmd) && isroom(line))
		farm->start = roomnew(line);
	if (!ft_strcmp("##end", cmd) && isroom(line))
		farm->end = roomnew(line);
}

void		readinput(t_farm *farm, char *aline)
{
	char	*line[21];
	size_t	i;

	i = -1;
	line[0] = "2";
	line[1] = "##start";;
	line[2] = "A 1 0";
	line[3] = "H 5 0";
	line[4] = "##end";
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
	(void)aline;
	while (++i < 21)
	{
		if (isnumber(line[i]) && !(farm->ants = 0))
			farm->ants = ft_getnbr(line[i]);
		else if (line[i][0] == '#' && line[i][1] == '#' && i++)
			read_cmd(farm, line[i - 1], line[i]);
		else if (line[i][0] == 'L' || line[i][0] == '#')
			continue ;
		else if (isroom(line[i]))
			setroom(line[i], &farm->room);
		else if (islink(line[i]))
			setlink(line[i], farm);
		else
			break ;
	}
}
