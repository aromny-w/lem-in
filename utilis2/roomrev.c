/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomrev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:13:21 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 16:15:08 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	roomrev(t_room **room)
{
	t_room	*prev;
	t_room	*curr;
	t_room	*next;

	prev = NULL;
	curr = *room;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*room = prev;
}
