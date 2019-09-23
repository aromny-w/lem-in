/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 15:03:55 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		validate(t_farm farm)
{
	ft_printf("%d %p %p\n", farm.ants, farm.start->links, farm.end->links);
	if (farm.ants < 0 || !farm.start->links || !farm.end->links)
		terminate(-1);
}

static void		initstruct(t_farm *farm)
{
	farm->ants = -1;
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
}

void			lem_in(char **input)
{
	t_farm	farm;
	t_ways	*ways;

	initstruct(&farm);
	(void)input;
	readinput(&farm, NULL);
	validate(farm);
	ways = bfs(&farm);
	print_ways(ways);
	destroyfarm(&farm);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	lem_in(++argv);
	terminate(1);
}
