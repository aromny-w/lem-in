/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:37:33 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 14:54:59 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
		if ((env->window = SDL_CreateWindow("Visu-Hex",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN)))
			if ((env->renderer = SDL_CreateRenderer(
				env->window, -1, SDL_RENDERER_ACCELERATED)))
				return ;
	ft_printf("%s\n", SDL_GetError());
	destroy_sdl(env);
}

void	destroy_sdl(t_env *env)
{
	env->run = 0;
	SDL_DestroyWindow(env->window);
	SDL_DestroyRenderer(env->renderer);
	SDL_Quit();
}

void	handle_key_down(t_env *env, SDL_Keycode key)
{
	(void)env;
	(void)key;
}

void	handle_key_up(t_env *env, SDL_Keycode key)
{
	(void)env;
	(void)key;
}

void	handle_event(t_env *env)
{
	if (env->e.type == SDL_QUIT)
		env->run = 0;
	if (env->e.type == SDL_KEYDOWN)
		handle_key_down(env, env->e.key.keysym.sym);
	if (env->e.type == SDL_KEYUP)
		handle_key_up(env, env->e.key.keysym.sym);
}
