/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:35:32 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 14:39:14 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*pathnew(t_way *way, size_t len)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		terminate(-1);
	path->way = way;
	path->len = len;
	path->limit = 0;
	return (path);
}
