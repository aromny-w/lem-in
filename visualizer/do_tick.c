/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_tick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:20:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 23:08:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void			tick_logic(t_env *env)
{
	if (env->key_up)
		env->y += env->camera_speed;
	if (env->key_down)
		env->y -= env->camera_speed;
	if (env->key_left)
		env->x -= env->camera_speed;
	if (env->key_right)
		env->x += env->camera_speed;
}

void			tick_render(t_env *env)
{
	render(env);
}

void			do_tick(t_env *env) 
{
	while (SDL_PollEvent(&env->e))
		handle_event(env);
	tick_logic(env);
	tick_render(env);
	SDL_Delay(env->delay);
}
