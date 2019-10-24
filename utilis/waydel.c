/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waydel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:18:55 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 00:21:49 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	waydel(t_way **way)
{
	t_way	*tmp;
	t_way	*next;

	tmp = *way;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*way = NULL;
}

