/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_readcommand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:01:14 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 15:14:43 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

int		visu_readcommand(t_env *env, int fd, char **line)
{
	char	cmd[ft_strlen(*line) + 1];

	ft_strcpy(cmd, *line);
	if (ft_strcmp("##start", cmd) && ft_strcmp("##end", cmd))
		return (0);
	free(*line);
	if (get_next_line(fd, line) != 1)
		*line = ft_strdup("");
	if (!visu_is_room(*line, env->room))
		;
	else if (!ft_strcmp("##start", cmd))
	{
		visu_setroom(*line, &env->start, env);
		roomadd(&env->room, env->start);
	}
	else if (!ft_strcmp("##end", cmd))
	{
		visu_setroom(*line, &env->end, env);
		roomadd(&env->room, env->end);
	}
	return (1);
}
