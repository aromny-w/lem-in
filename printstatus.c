/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstatus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:45:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 18:11:04 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printstatus(t_path **path, int k)
{
	size_t	i;

	i = 0;
	printf("k = %d\n", k);
	while (path[i] && path[i]->way)
	{
		if (path[i]->way->next)
			printf("%s%s->", path[i]->way->room->name, path[i]->way->room->in ? "(in)" : path[i]->way->room->out ? "(out)" : "");
		else
			printf("%s\n", path[i]->way->room->name);
		path[i]->way = path[i]->way->next;
	}
}
