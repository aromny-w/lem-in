/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:47:52 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 17:23:30 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	render(t_env *env)
{
	ft_printf("do_tick");
	SDL_SetRenderDrawColor(env->renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(env->renderer);
	SDL_SetRenderDrawColor(env->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderPresent(env->renderer);
}
