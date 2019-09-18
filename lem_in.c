/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:24:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/18 17:14:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		validate(t_farm farm)
{
	// validate data
//	if (farm.ants < 0 || !farm.start->links || !farm.end->links)
//		terminate(-1);
	(void)farm;
}

static void		initstruct(t_farm *farm)
{
	farm->ants = 0;
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
}

void			lem_in(char **input)
{
	t_farm	farm;

	initstruct(&farm);
	(void)input;
	readinput(&farm, NULL);
	ft_printf("%d\n", farm.ants);
	t_room *ptr = farm.room;
	ft_printf("%s %d %d\n", farm.start->name, farm.start->in, farm.start->out);
	ft_printf("%s %d %d\n", farm.end->name, farm.end->in, farm.end->out);
	while (ptr)
	{
		ft_printf("%s %d %d\n", ptr->name, ptr->in, ptr->out);
		ptr = ptr->next;
	}
	validate(farm);
	solvefarm(&farm);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	lem_in(++argv);
	terminate(1);
}
