/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/23 18:07:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		validate(t_farm farm)
{
	if (farm.ants < 0)
		terminate(-1);
	if (!farm.start || !farm.end || !farm.start->links || !farm.end->links)
		terminate(-1);
}

static void		initstruct(t_farm *farm)
{
	farm->ants = -1;
	farm->room = NULL;
	farm->split_room = NULL;
	farm->start = NULL;
	farm->end = NULL;
}

void			lem_in(int fd)
{
	t_farm	farm;
	t_ways	*ways;

	initstruct(&farm);
	readinput(&farm, fd, NULL);
	validate(farm);
	ways = bfs(&farm);
	print_ways(ways);
	destroyfarm(&farm);
}

int				main(int argc, char **argv)
{
	if (argc == 1)
		lem_in(0);
	else if (argc == 2)
		lem_in(open(argv[1], O_RDONLY));
	else
		terminate(-1);
	terminate(1);
}
