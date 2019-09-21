/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isroom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:47:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 21:47:10 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		iscoord2(char **line)
{
	long	nbr;

	nbr = 0;
	if (**line == '-')
		return (0);
	while (ft_isdigit(**line) && nbr <= INT_MAX)
		nbr = 10 * nbr + (*(*line)++ - '0');
	if (**line == '\0' && nbr <= INT_MAX)
		return (1);
	return (0);
}

static int		iscoord1(char **line)
{
	long	nbr;

	nbr = 0;
	if (**line == '-')
		return (0);
	while (ft_isdigit(**line) && nbr <= INT_MAX)
		nbr = 10 * nbr + (*(*line)++ - '0');
	if (*(*line)++ == ' ' && nbr <= INT_MAX)
		return (1);
	return (0);
}

static size_t	namelen(char *line)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

static int		isname(char **line, t_farm farm)
{
	char	name[1 + namelen(*line)];
	size_t	i;

	i = 0;
	while (ft_isalnum(**line) || **line == '_')
		name[i++] = *(*line)++;
	name[i] = '\0';
	if (farm.start && !ft_strcmp(name, farm.start->name))
		return (0);
	if (farm.end && !ft_strcmp(name, farm.end->name))
		return (0);
	while (farm.room)
	{
		if (ft_strcmp(name, farm.room->name))
			farm.room = farm.room->next;
		else
			break ;
	}
	if (*(*line)++ == ' ' && !farm.room)
		return (1);
	return (0);
}

int				isroom(char *line, t_farm farm)
{
	if (*line == 'L' || *line == '#')
		return (0);
	if (!isname(&line, farm))
		return (0);
	if (!iscoord1(&line))
		return (0);
	if (!iscoord2(&line))
		return (0);
	return (1);
}
