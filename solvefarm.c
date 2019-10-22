/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/22 18:04:11 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		brakingsystem(t_path *path, int k, int ants)
{
	int	i;
	int	sum;

	sum = 0;
	i = -1;
	while (++i + 1 < k)
		sum += (path[i + 1].len / 2  - (path[i].len) / 2) * (i + 1);
	if (sum < ants)
		return (1);
	return (0);
}

void			solvefarm(t_farm farm, size_t max)
{
	t_path	*path[1 + max];
	size_t	k;

	k = 0;
	path[k] = NULL;
	splitrooms(&farm.room, farm.start, farm.end);
	while (++k <= max)
	{
		if (!(path[k] = getpaths(farm, path[k - 1], k)) || 
		!brakingsystem(path[k], k, farm.ants))
			break ;
		//printf("k = %zu\n", k);
		//printstatus(path[k], k);
	}
	//ants_move(path[k - 1], k - 1 , &farm);
	antsdist(path[k - 1], k - 1, farm.ants);
}
