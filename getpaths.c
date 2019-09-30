/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpaths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:35:51 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/30 22:13:21 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*getpaths(t_farm farm, t_path *init, size_t k)
{
	t_path	*path;
	size_t	i;

	i = 0;
	if (!(path = (t_path *)malloc(sizeof(t_path) * k)))
		terminate(-1);
	while (i < k)
		path[i++] = pathnew(NULL, 0);
	findpaths(farm, path, init, k);
	return (path);
}
