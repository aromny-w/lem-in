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

void	printstatus(t_path *path, int k)
{
	t_path	*tmp;
	size_t	i;

	i = -1;
	printf("k = %d\n", k);
	while (++i < k)
	{
		tmp = &path[i];
		while (tmp && tmp->way)
		{
			if (tmp->way->next)
				printf("%s%s->", tmp->way->room->name, tmp->way->room->in ? "(in)" : tmp->way->room->out ? "(out)" : "");
			else
				printf("%s\n", tmp->way->room->name);
			tmp->way = tmp->way->next;
		}
	}
}
