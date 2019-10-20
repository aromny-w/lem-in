/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:00:26 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 21:21:45 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	render_ant(SDL_Renderer *rend, int x, int y)
{
	SDL_Rect ant;
	
	ant.x = x;
	ant.y = y;
	ant.w = 5;
	ant.h = 5;
	SDL_RenderDrawRect(rend, &rend);
}

void	render_ants(t_env *env, t_ants_renderer *ants)
{
	t_ants_renderer *ptr;

	ptr = ants;
	while (ptr)
	{
		render_ant(env->renderer, ptr->x, ptr->y);
		ptr = ptr->next;
	}
}
