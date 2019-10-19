/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-reader-predictions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:38:52 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 19:38:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

int		visu_isantnbr(char *line)
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

int		visu_is_room(char *line, t_room *room)
{
	if (*line == 'L' || *line == '#')
		return (0);
	if (!isname(&line, room))
		return (0);
	if (!iscoord1(&line))
		return (0);
	if (!iscoord2(&line))
		return (0);
	return (1);
}

int				visu_islink(char *line, t_room *room)
{
	char	name1[1 + namelen1(line)];
	char	name2[1 + namelen2(line)];
	size_t	i;
	size_t	j;

	if (*line == 'L')
		return (0);
	i = 0;
	j = 0;
	while (ft_isalnum(*line) || *line == '_')
		name1[i++] = *line++;
	name1[i] = '\0';
	if (*line++ != '-')
		return (0);
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		name2[j++] = *line++;
	name2[j] = '\0';
	(void)room;
	if (!*line)
		return (1);
	return (0);
}

int					visu_iscommand(char *line)
{
	if (*line == '#' && *(line + 1) == '#')
		return (1);
	return (0);
}

int					visu_iscomment(char *line)
{
	if (*line == '#' && *(line + 1) != '#')
		return (1);
	return (0);
}
