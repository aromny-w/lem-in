/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:04:51 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 21:48:48 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void	visu_add_step(t_env *env, char *step)
{
	if (*step == '\0' || *step == '\n')
		return;
	if (env->step == NULL)
	{
		env->step = (t_step*)malloc(sizeof(t_step));
		env->step->step = step;
		env->step->prev = NULL;
		env->step->next = NULL;
		return ;
	}
	while (env->step->next != NULL)
		env->step = env->step->next;
	env->step->next = (t_step*)malloc(sizeof(t_step));
	env->step->next->step = step;
	env->step->next->prev = env->step;
	env->step->next->next = NULL;
}

void	visu_setroom(char *line, t_room **room, t_env *env)
{
	t_room *new;
	char *name;
	t_point coords;
	size_t len;

	len = 0;
	while (line[len] != ' ')
		len++;
	name = ft_strsub(line, 0, len);
	coords.x = ft_getnbr(line + ++len);
	while (line[len] != ' ')
		len++;
	coords.y = ft_getnbr(line + ++len);
	new = roomnew(name, coords, NULL);
	roomadd(room, new);
	env->rooms_cnt++;
	set_maxmincoords(env, coords);
}

t_room	*visu_find_room_by_name(char *name, t_room *room)
{
	t_room	*ptr;

	ptr = room;
	while (ptr)
	{
		if (!ft_strcmp(name, ptr->name))
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	visu_setlink(char *line, t_visu_link **link, t_env *env)
{
	char			**room_names;
	t_visu_link		*new;
	
	if (!(new = (t_visu_link*)malloc(sizeof(t_visu_link))))
		terminate(-1);
	room_names = ft_strsplit(line, '-');
	if (!room_names || !room_names[0] || !room_names[1])
		terminate(-1);
	
	new->room1 = visu_find_room_by_name(room_names[0], env->room);
	new->room2 = visu_find_room_by_name(room_names[1], env->room);
	if (!new->room1 || !new->room2)
		return;
	new->next = NULL;
	free(room_names[0]);
	free(room_names[1]);
	free(room_names);
	addnewlink(env, link, new);
	env->links_cnt += 1;
}

void	visu_reader(t_env *env, char *line, int fd)
{
	int s[4];

	s[0] = 0;
	s[1] = 0;
	s[2] = 0;
	s[3] = 0;
	(void)env;
	while (get_next_line(fd, &line) == 1)
	{
		if (visu_isantnbr(line) && !s[1] && !s[2] && (s[0] = 1))
			env->ants = ft_getnbr(line);
		else if (visu_is_room(line, env->room) && s[0] && !s[2] && (s[1] = 1))
			visu_setroom(line, &env->room, env);
		else if (visu_islink(line, env->room) && s[0] && s[1] && (s[2] = 1))
			visu_setlink(line, &env->link, env);
		else if (visu_iscomment(line))
			;
		else if (visu_iscommand(line))
			;
		else
			visu_add_step(env, ft_strdup(line));
		if (line)
			free(line);
	}
}
