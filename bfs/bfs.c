/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 08:39:04 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 16:02:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		bfs_stend_check(t_bfs *bfs, t_farm *farm, t_way **way)
{
	if (bfs->matrix[farm->start_id][farm->end_id] == 1
		|| bfs->matrix[farm->end_id][farm->start_id] == 1)
		{
			;
			*way = init_way(farm->end);
			return (1);
		}
	return (0);
}

void	bfs_level_up(int **q, int **q1, int size)
{
	free(*q);
	*q = *q1;
	*q1 = queue(size);
}

int		get_linked(t_bfs *bfs, int cur, int *linked)
{
	int	i;

	i = 0;
	while (i < bfs->matrix_size)
	{
		if (bfs->matrix[cur][i] && bfs->v[i] == 0)
		{
			*linked = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	bfs_add_dist(t_farm *farm, t_bfs *bfs)
{
	int		cur;
	int		linked;
	int		i;
	
	i = 1;
	bfs->q1 = bfs_queue(bfs->matrix_size);
	cur = farm->start_id;
	bfs->v[cur] = 1;
	bfs_enqueue(bfs->q, cur);
	while (bfs->q[2] != 0)
	{
		cur = bfs_dequeue(bfs->q);
		while (get_linked(bfs, cur, &linked))
		{
			bfs->v[linked] = 1;
			bfs->d[linked] = i;
			bfs->p[linked] = cur;
			bfs_enqueue(bfs->q1, linked);
		}
		if (bfs->q[2] == 0 && ++i)
			bfs_level_up(&(bfs->q), &(bfs->q1), bfs->matrix_size);
	}
	bfs->p[farm->start_id] = -1;
	free(bfs->q);
	free(bfs->q1);
	return (0);
}

t_way	*bfs(t_farm *farm, t_bfs *bfs)
{
	t_way	*way;

	way = NULL;
	bfs->q = bfs_queue(bfs->matrix_size);
	// if (bfs_stend_check(bfs, farm, &way))
	// 	return (way);
	bfs_add_dist(farm, bfs);
	bfs->i = farm->end_id;
	if (bfs->p[bfs->i] == -1)
		return (NULL);
	bfs->latest_dist = 0;
	while (bfs->i != -1)
	{
		wayadd(&way, waynew(find_room_by_num(farm, bfs->i)));
		bfs->i = bfs->p[bfs->i];
		bfs->latest_dist++;
	}
	way->dist = bfs->latest_dist;
	return (way);
}
