/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/26 20:32:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	getminvalue(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

void			solvefarm(t_farm farm)
{
	t_path	*path[1 + getminvalue(farm.ants, farm.end->links)];
	int		k;

	k = 0;
	path[k++] = NULL;
	splitrooms(&farm.room, farm.start, farm.end);
	printrooms(farm.room);
	while (k < farm.ants + 1)
	{
		path[k] = getpaths(farm, path[k - 1], k);
		printstatus(path[k], k);
		if (!path[k++])
			break ;
	}
}
