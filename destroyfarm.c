/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyfarm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:23:40 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/07 04:39:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	destroylinks(t_link **link)
{
	t_link	*tmp;
	t_link	*next;

	tmp = *link;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void		destroyfarm(t_farm *farm)
{
	t_room	*tmp;
	t_room	*next;

	tmp = farm->room;
	while (tmp)
	{
		next = tmp->next;
		destroylinks(&tmp->link);
		if (!tmp->in)
			free(tmp->name);
		free(tmp);
		tmp = next;
	}
	farm = NULL;
}

void		destroyfarmways(t_farm *farm, t_ways *ways, char **out)
{
	destroyfarm(farm);
	destroy_ways(ways);
	if (out && *out)
		free(*out);
	out = NULL;
	exit(-1);
}
