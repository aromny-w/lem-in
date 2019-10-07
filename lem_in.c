/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/07 05:01:37 by bharrold         ###   ########.fr       */
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

static void		initfarm(t_farm *farm)
{
	farm->ants = -1;
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
}

void			lem_in(int fd)
{
	t_farm	farm;
	t_ways	*ways;
	char	*out;

	out = NULL;
	initfarm(&farm);
	readinput(&farm, fd, NULL, &out);
	validate(farm);
	if ((ways = bfs(&farm))->dist == -1)
		destroyfarmways(&farm, ways, &out);
	ft_putendl(out);
	write(1, "\n", 1);
	if (ways->dist == 1)
		all_ants_one_way(&farm, ways);
	else
		lets_go(&farm, ways, farm.ants, ways);
	destroyfarmways(&farm, ways, &out);
	free(out);
}

int				main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		lem_in(0);
	else if (argc == 2)
		lem_in(open(argv[1], O_RDONLY));
	else
		terminate(-1);
}
