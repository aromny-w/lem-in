/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:35:32 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/22 16:25:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	pathnew(t_way *way, size_t len)
{
	t_path	path;

	path.way = way;
	path.len = len;
	path.limit = 0;
	return (path);
}
