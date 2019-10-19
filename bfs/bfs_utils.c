/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:03:55 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 13:06:02 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_rooms(t_farm *farm)
{
	t_room	*ptr;
	int		i;

	i = 0;
	ptr = farm->room;
	while (ptr)
	{
		ptr->visited = 0;
		ptr->excluded = 0;
		ptr->dist = 0;
		if (ptr == farm->start)
			farm->start_id = i;
		if (ptr == farm->end)
			farm->end_id = i;
		ptr->num = i;
		i++;
		ptr = ptr->next;
	}
}

void	init_bfs(t_bfs *bfs, t_farm *farm)
{
	int	i;

	(bfs)->matrix = farm->matrix;
	(bfs)->matrix_size = farm->rooms_cnt;
	(bfs)->v = (int*)malloc(sizeof(int) * farm->rooms_cnt);
	(bfs)->d = (int*)malloc(sizeof(int) * farm->rooms_cnt);
	(bfs)->p = (int*)malloc(sizeof(int) * farm->rooms_cnt);
	i = 0;
	while (i < farm->rooms_cnt)
	{
		bfs->v[i] = 0;
		bfs->d[i] = 0;
		bfs->p[i] = -1;
		i++;
	}
}

void	reset_bfs(t_bfs *bfs, t_farm *farm)
{
	int	i;

	i = 0;
	while (i < farm->rooms_cnt)
	{
		bfs->v[i] = 0;
		bfs->d[i] = 0;
		bfs->p[i] = -1;
		i++;
	}
}

void	destroy_bfs(t_bfs *bfs)
{
	free(bfs->v);
	free(bfs->d);
	free(bfs->p);
}

void	init_search(t_farm *farm)
{
	int		i;

	i = 0;
	splitrooms(&(farm->room), farm->start, farm->end);
	init_rooms(farm);
	farm->rooms_cnt = get_rooms_count(farm);
	farm->matrix = create_matrix(farm->rooms_cnt);
	farm->e_matrix = create_matrix(farm->rooms_cnt);
	fill_matrix(&(farm->matrix), farm);
	fill_matrix(&(farm->e_matrix), farm);
	farm->limit_variations = get_limit(farm);
	farm->ways = (t_ways**)malloc(sizeof(t_ways*) * farm->limit_variations);
	farm->ways_variations_cnt  = malloc(sizeof(int) * farm->limit_variations);
	while (i < farm->limit_variations)
	{
		farm->ways[i] = NULL;
		farm->ways_variations_cnt[i] = 0;
		i++;
	}
	farm->real_variations = 0;
}
