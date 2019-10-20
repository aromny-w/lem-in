/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:25:20 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/25 16:15:04 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wayrev(t_way **way)
{
	t_way	*prev;
	t_way	*curr;
	t_way	*next;

	prev = NULL;
	curr = *way;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*way = prev;
}
