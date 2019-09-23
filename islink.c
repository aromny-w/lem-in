/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:48:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 21:48:17 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static int		isdupelink(t_farm farm, char *name1, char *name2)
{
	if (farm.start && !ft_strcmp(name1, farm.start->name))
	{
		while (farm.start->link &&
		ft_strcmp(name2, farm.start->link->room->name))
			farm.start->link = farm.start->link->next;
		return (farm.start->link ? 1 : 0);
	}
	if (farm.end && !ft_strcmp(name1, farm.end->name))
	{
		while (farm.end->link && ft_strcmp(name2, farm.end->link->room->name))
			farm.end->link = farm.end->link->next;
		return (farm.end->link ? 1 : 0);
	}
	if (farm.room)
	{
		while (ft_strcmp(name1, farm.room->name))
			farm.room = farm.room->next;
		while (farm.room->link)
		{
			if (!ft_strcmp(name2, farm.room->link->room->name))
				return (1);
			farm.room->link = farm.room->link->next;
		}
	}
	return (0);
}

static int		isexist(t_farm farm, char *name)
{
	if (farm.start && !ft_strcmp(name, farm.start->name))
		return (1);
	if (farm.end && !ft_strcmp(name, farm.end->name))
		return (1);
	while (farm.room && ft_strcmp(name, farm.room->name))
		farm.room = farm.room->next;
	if (farm.room)
		return (1);
	return (0);
}

static size_t	namelen2(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line != '-')
		line++;
	if (!*line++)
		return (0);
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

static size_t	namelen1(char *line)
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

int				islink(char *line, t_farm farm)
{
	char	name1[1 + namelen1(line)];
	char	name2[1 + namelen2(line)];
	size_t	i;
	size_t	j;

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
	if (!isexist((farm), name1) || !isexist(farm, name2))
		return (0);
	if (isdupelink(farm, name1, name2)) //links are moving somehow, fix later
		return (0);
	if (!*line)
		return (1);
	return (0);
}*/


int	islink(char *line, t_farm farm)
{
	(void)farm;
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
