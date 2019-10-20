/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_tick_count_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 21:32:04 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 22:04:47 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	set_xy_send(t_env *env, t_ants_renderer **aren, t_room *room1,
	t_room *room2)
{
	(*aren)->x1 = room1->coords.x;
	(*aren)->y1 = room1->coords.y;
	(*aren)->x2 = room2->coords.x;
	(*aren)->y2 = room2->coords.y;
	(*aren)->x = room1->coords.x;
	(*aren)->y = room1->coords.y;
}

t_room	*find_room(t_room *room, char *name)
{
	t_room *ptr;

	ptr = room;
	while (ptr)
	{
		if (!ft_strsplit(room->name, name))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	free_move(char ***move)
{

}

void	parse_step(t_env *env, char **strs, char **move)
{
	char **ptr;
	t_ants_renderer	*aptr;
	t_ants_renderer	*new;

	strs = ft_strsplit(env->step->step, ' ');
	ptr = strs;
	env->step->aren = (t_ants_renderer*)ft_memalloc(sizeof(t_ants_renderer));
	aptr = env->step->aren;
	move = ft_strsplit(ptr[1], '-');
	set_xy_send(env, &aptr, env->start, find_room(env->room, ptr[1]));
	free (move[0]);
	free(move[1]);
	free(move);
	ptr++;
	while (ptr)
	{
		if (!(new = (t_ants_renderer*)ft_memalloc(sizeof(t_ants_renderer))))
			terminate(-1);
		
		aptr->next = new;
		ptr++;
	}
}

void	count_ants(t_env *env)
{
	if (env->step->aren == NULL)
	{
		parse_step(env, NULL, NULL);
	}
}
