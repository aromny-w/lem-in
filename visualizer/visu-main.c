/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:08:00 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 20:06:39 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void			init_keys(t_env *env)
{
	env->key_down = 0;
	env->key_up = 0;
	env->key_left = 0;
	env->key_right = 0;
}

void			init_camera(t_env *env)
{
	env->x = 0;
	env->y = 0;
	env->camera_speed = 10;
}

void			init_screen(t_env *env)
{
	env->room_radius = 10;
	env->width_persize = 50;
	env->height_persize = 50;
}

void			initialize_visualizer(t_env *env, int fd)
{
	env->run = 1;
	env->delay = 1;
	env->step = NULL;
	env->room = NULL;
	env->link = NULL;
	env->rooms_cnt = 0;
	env->links_cnt = 0;
	env->max_x_coord = INT_MIN;
	env->max_y_coord = INT_MIN;
	env->min_x_coord = INT_MAX;
	env->min_y_coord = INT_MAX;
	visu_reader(env, NULL, fd);
	while (env->step->prev != NULL)
		env->step = env->step->prev;
	init_screen(env);
	init_camera(env);
	init_keys(env);
}

int				main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	t_env env;
	int	fd;
	
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		initialize_visualizer(&env, fd);
		close(fd);
	} 
	else
	{
		initialize_visualizer(&env, 0);
	}
	init_sdl(&env);
	while (env.run)
	{
		do_tick(&env);
	}
	destroy_sdl(&env);
}
