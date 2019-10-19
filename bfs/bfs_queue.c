/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 09:37:56 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 17:27:38 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	bfs_enqueue(int *q, int num)
{
	q[++q[0]] = num;
	q[2]++;
}

int		bfs_dequeue(int *q)
{
	q[2]--;
	return (q[q[1]++]);
}

int		*bfs_queue(int size)
{
	int *q;

	q = (int*)malloc(sizeof(int) * (size + 3));
	q[0] = 2;
	q[1] = 3;
	q[2] = 0;
	return (q);
}
