/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 18:46:19 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		validate(t_farm farm)
{
	if (farm.ants <= 0)
		return (0);
	if (!farm.start || !farm.end || !farm.start->links || !farm.end->links)
		return (0);
	return (1);
}

void			lem_in(int fd)
{
	t_farm	farm;

	initfarm(&farm);
	readinput(&farm, fd, NULL);
	if (!validate(farm))
		destroyfarm(&farm, NULL, 1);
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
