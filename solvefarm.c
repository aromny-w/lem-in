/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/03 22:50:20 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	getminvalue(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

void			solvefarm(t_farm farm, size_t max)
{
	t_path	*path[1 + getminvalue(farm.ants, farm.end->links)];
	size_t	k;

	k = 0;
	path[k] = NULL;
	splitrooms(&farm.room, farm.start, farm.end);
	while (++k <= max)
	{
		if (!(path[k] = getpaths(farm, path[k - 1], k)))
			break ;
		printf("%zu\n", k);
		printstatus(path[k], k);
	}
}
