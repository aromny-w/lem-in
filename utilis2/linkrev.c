/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:15:22 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 16:16:25 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	linkrev(t_link **link)
{
	t_link	*prev;
	t_link	*curr;
	t_link	*next;

	prev = NULL;
	curr = *link;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*link = prev;
}
