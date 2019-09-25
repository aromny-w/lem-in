/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstatus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:45:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 19:44:04 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	printpaths(t_path path)
{
	while (path.way)
	{
		if (path.way->next)
		{
			if (path.way->room->in)
				printf("%s%s->", path.way->room->name, "(in)");
			else if (path.way->room->out)
				printf("%s%s->", path.way->room->name, "(out)");
			else
				printf("%s->", path.way->room->name);
		}
		else
			printf("%s\n", path.way->room->name);
		path.way = path.way->next;
	}
}

void		printstatus(t_path *path, int k)
{
	int		i;

	i = -1;
	while (++i < k)
		printpaths(path[i]);
}
