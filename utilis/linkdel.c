/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 22:11:13 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/19 22:12:17 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	linkdel(t_link **link)
{
	t_link	*tmp;
	t_link	*next;

	tmp = *link;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*link = NULL;
}
