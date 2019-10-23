/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortpaths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:05:26 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/23 23:53:00 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pathswap(t_path *a, t_path *b)
{
	t_path	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sortpaths(t_path *path, size_t k)
{
	size_t	i;

	i = 0;
	while (i + 1 < k && path[i].way && path[i + 1].way)
	{
		if (path[i].len > path[i + 1].len)
		{
			pathswap(&path[i], &path[i + 1]);
			i = 0;
		}
		i++;
	}
}
