/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:51 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 17:02:40 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*tryagain(t_farm *farm, t_path *init, size_t k)
{
	farm->depth = INFINITY;
	return (getpaths(farm, init, k));
}

t_path			*getpaths(t_farm *farm, t_path *init, size_t k)
{
	t_path	*path;
	size_t	i;

	i = -1;
	if (!(path = (t_path *)malloc(sizeof(t_path) * k)))
		terminate(-1);
	while (++i < k - 1 && init)
	{
		path[i].way = init[i].way;
		path[i].len = init[i].len;
		path[i].limit = init[i].limit;
	}
	ft_memset(&path[i], 0, sizeof(path[i]));
	if (!findpaths(farm, path, k))
	{
		free(path);
		if (k == 1 && farm->depth != INFINITY)
			return (tryagain(farm, init, k));
		return (NULL);
	}
	return (path);
}
