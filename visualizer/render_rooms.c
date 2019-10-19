/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:14:00 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 23:07:12 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"


void	render_rooms(t_env *env)
{
	t_room *ptr;
	
	set_pixel(env->renderer, 255, 255, 0);
	ptr = env->room;
	while (ptr)
	{
		sdl_draw_circle(env->renderer, 
		START_X + ptr->coords.x * env->width_persize - env->x, 
		START_Y + ptr->coords.y * env->height_persize - env->y, 
		env->room_radius);
		ptr = ptr->next;
	}
	
	(void)env;
}

void	render_links(t_env *env)
{
	t_visu_link *ptr;

	set_pixel(env->renderer, 0, 255, 0);
	ptr = env->link;
	while (ptr)
	{
		SDL_RenderDrawLine(env->renderer,
		START_X + ptr->room1->coords.x * env->width_persize - env->x,
		START_Y + ptr->room1->coords.y * env->height_persize - env->y,
		START_X + ptr->room2->coords.x * env->width_persize - env->x,
		START_Y + ptr->room2->coords.y * env->height_persize - env->y);
		ptr = ptr->next;
	}
}
