/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 05:18:38 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 05:56:23 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	enqueue(int *q, int num)
{
	q[++q[0]] = num;
	q[2]++;
}

t_room	*dequeue(int *q, t_farm *farm)
{
	q[2]--;
	return (find_room_by_num(farm, q[q[1]++]));
}

int		*queue(int size)
{
	int *q;

	q = (int*)malloc(sizeof(int) * (size + 3));
	q[0] = 2;
	q[1] = 3;
	q[2] = 0;
	return (q);
}
