/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_islink_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:45:52 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 15:16:00 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

size_t	namelen2(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line != '-')
		line++;
	if (!*line++)
		return (0);
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

size_t	namelen1(char *line)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

void	addnewlink(t_env *env,t_visu_link **link, t_visu_link *new)
{
	
	t_visu_link		*ptr;
	
	(void)env;
	if (!(*link))
		*link = new;
	else
	{
		ptr = *link;	
		while (ptr && (ptr)->next != NULL)
			ptr = (ptr)->next;
		(ptr)->next = new;
	}
}
