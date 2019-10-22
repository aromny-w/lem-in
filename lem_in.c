/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/22 22:24:53 by aromny-w         ###   ########.fr       */
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
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->buf = NULL;
}

void			lem_in(int fd)
{
	t_farm	farm;

	initfarm(&farm);
	readinput(&farm, fd, NULL);
	if (!validate(farm))
	{
		destroyfarm(&farm);
		terminate(-1);
	}
	writeinput(farm.buf);
	solvefarm(farm, farm.end->links > farm.ants ? farm.ants : farm.end->links);
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
