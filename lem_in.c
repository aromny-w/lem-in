/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/02 20:24:38 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		validate(t_farm farm)
{
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

	initstruct(&farm);
	readinput(&farm, NULL);
	validate(farm);
	solvefarm(&farm);
}

int				main(int argc, char **argv)
{
	lem_in(++argv);
	terminate(1);
}
