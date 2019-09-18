/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstatus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:45:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 16:45:16 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printstatus(t_path **path, int k)
{
	size_t	i;

	i = 0;
	printf("%d solution\n", k);
	while (path[i] && path[i]->way)
	{
		if (path[i]->way->next)
			printf("%s->", path[i]->way->room->name);
		else
			printf("%s", path[i]->way->room->name);
		path[i]->way = path[i]->way->next;
	}
}
