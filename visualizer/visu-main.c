/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:08:00 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 16:38:35 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void			initialize_visualizer(t_env *env)
{
	env->run = 1;
	env->delay = 1;
	env->step = NULL;
	visu_reader(env, NULL);
	ft_printf("%d\n", env->ants);
	
	t_room *ptr = env->room;
	while (ptr)
	{
		ft_printf("%s (%d %d)\n", ptr->name, ptr->coords.x, ptr->coords.y);
		ptr = ptr->next;
	}
	t_visu_link *ptrr;
	ptrr = env->link;
	ft_printf("\n");
	while (ptrr)
	{
		ft_printf("%s-%s\n", ptrr->room1->name, ptrr->room2->name);
		ptrr = ptrr->next;
	}
}

void			do_tick(t_env *env) 
{
	while (SDL_PollEvent(&env->e))
		handle_event(env);
	render(env);
	SDL_Delay(env->delay);
}

int				main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	t_env env;

	initialize_visualizer(&env);
	//init_sdl(&env);
	// while (env.run)
	// {
	// 	do_tick(&env);
	// }
	destroy_sdl(&env);
}
