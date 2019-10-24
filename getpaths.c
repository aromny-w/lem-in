/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:51 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 15:25:15 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	path[i].way = NULL;
	path[i].len = 0;
	path[i].limit = 0;
	if (!findpaths(farm, path, k))
	{
		free(path);
		return (NULL);
	}
	return (path);
}
