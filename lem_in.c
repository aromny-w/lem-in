/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/19 18:50:54 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		writeinput(t_list *buf)
{
	while (buf)
	{
		ft_putendl(buf->content);
		buf = buf->next;
	}
	ft_putchar('\n');
}

static int		validate(t_farm farm)
{
	if (farm.ants < 0)
		return (0);
	if (!farm.start || !farm.end || !farm.start->links || !farm.end->links)
		return (0);
	return (1);
}

static void		initfarm(t_farm *farm)
{
	farm->ants = -1;
	farm->buf = NULL;
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
}

void			lem_in(int fd)
{
	t_farm	farm;
	t_ways	*ways;

	ways = NULL;
	initfarm(&farm);
	readinput(&farm, fd, NULL);
	validate(farm);
	search_ways(&farm);
	if (!farm.ways[farm.real_variations])
		terminate(-1);
	if ((farm.ways[farm.real_variations])->dist == 0)
		terminate(-1);
	writeinput(farm.buf);
	ft_printf("\n");
	if (farm.ways[farm.real_variations]->dist == 1)
		all_ants_one_way(&farm, farm.ways[farm.real_variations]);
	else
		lets_go(&farm, farm.ways[0], farm.ants, farm.ways[0]);
	destroyfarmways(&farm, ways);
}

int				main(int argc, char **argv)
{
	(void) argv;
	if (argc == 1)
		lem_in(0);
	else if (argc == 2)
		lem_in(open(argv[1], O_RDONLY));
	else
		terminate(-1);
}
