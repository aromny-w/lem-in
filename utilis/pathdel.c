/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:14:55 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 15:20:37 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pathdel(t_path **path)
{
	t_path	*tmp;
	t_path	*next;

	tmp = *path;
	while (tmp)
	{
		next = tmp->next;
		waydel(&tmp->way);
		free(tmp);
		tmp = next;
	}
	*path = NULL;
}
