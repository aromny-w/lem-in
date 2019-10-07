/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 08:53:09 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/07 15:10:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	debug_search(t_farm *farm)
{
	t_room	*ptr;

	ptr = farm->room;
	ft_printf("start_id %d; end_id %d\n", farm->start_id, farm->end_id);
	while (ptr)
	{
		ft_printf("%s\t %d\n", ptr->name, ptr->num);
		ptr = ptr->next;
	}
}

int		search_rev_matrix(int ***matrix, t_way *way)
{
	t_way	*ptr;
	t_way	*next;
	int		i = 0;
	
	ptr = way;
	next = ptr->next;
	while (next)
	{
		(*matrix)[ptr->room->num][next->room->num] = ((*matrix)[ptr->room->num][next->room->num]) ? 0 : 1;
		(*matrix)[next->room->num][ptr->room->num] = ((*matrix)[next->room->num][ptr->room->num]) ? 0 : 1;
		ptr = ptr->next;
		next = next->next;
		i++;
	}
	return (i);
}

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

void	copy_e_matrix(int ***matrix, int **e_matrix, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			(*matrix)[i][j] = e_matrix[i][j];
	}
}

int		get_limit(t_farm *farm)
{
	int lim;

	if (farm->rooms_cnt < 2000)
		lim = 12;
	else
	{
		lim = 6;
		if (farm->ants > 130)
			lim = 7;
		if (farm->ants > 175)
			lim = 8;
		if (farm->ants > 200)
			lim = 9;
		if (farm->ants > 220)
			lim = 10;
		if (farm->ants > 250)
			lim = 12;
		if (farm->ants > 325)
			lim = 13;
		if (farm->ants > 450)
			lim = 14;
	}
	if (farm->end->links < lim)
		lim = farm->end->links;
	if (farm->ants < lim)
		lim = farm->ants;
	return (lim);
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

int		check_overlap(t_way *way, t_farm **farm, t_bfs *bfs)
{
	t_way	*ptr;
	t_way	*next;

	ptr = way;
	next = ptr->next;
	while (next)
	{
		if ((ptr->room->name == next->room->name && ptr->room->out &&
			next->room->in) || (ptr->room->name != next->room->name &&
			ptr->room->in && next->room->out))
		{
			(*farm)->e_matrix[ptr->room->num][next->room->num] = 0;
			(*farm)->e_matrix[next->room->num][ptr->room->num] = 0;
			{
				copy_e_matrix(&bfs->matrix, (*farm)->e_matrix, (*farm)->rooms_cnt);
				return (1);
			}
			
		}
		ptr = ptr->next;
		next = next->next;
	}
	return (0);
}

int		lenway(t_way *way)
{
	t_way	*ptr;
	int		i;

	i  = 0;
	ptr = way;
	while (ptr)
	{
		i++;
		ptr->ant = 0;
		ptr = ptr->next;
	}
	return (i);
}

void	push_to_ways(t_ways ***ways, t_way *way, int num, t_farm *farm)
{
	t_ways *ptr;
	
	farm->real_variations = num;
	farm->ways_variations_cnt[num] += 1;
	if (!(*ways)[num])
	{
		(*ways)[num] = init_ways();
		(*ways)[num]->way = way;
		(*ways)[num]->next = NULL;
		(*ways)[num]->dist = 0;
		(*ways)[num]->dist = lenway(way);
		return ;
	}
	else
	{
		ptr = (*ways)[num];
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = init_ways();
		ptr->next->way = way;
		ptr->next->dist = lenway(way);
	}
}


t_way	*normal_way(t_way *way)
{
	t_way	*ptr;
	t_way	*cur;

	ptr = way;
	cur = NULL;
	cur = ptr;
	ptr = ptr->next;
	way = way->next;
	free(cur);
	while (ptr && ptr->next)
	{
		if (ptr->room->name == ptr->next->room->name)
		{
			cur = ptr->next;
			ptr->next = ptr->next->next;
			free(cur);
			continue;
		}
		ptr = ptr->next;
	}
	return (way);
}

void	search_ways(t_farm *farm)
{
	t_bfs	bfso;
	t_way	*tmp;
	int		lim;
	int		k;

	lim = 0;
	k = 0;
	init_search(farm);
	init_bfs(&bfso, farm);
	while (lim < farm->limit_variations && k < farm->limit_variations + 1
		&& (tmp = bfs(farm, &bfso)))
	{
		
		if (check_overlap(tmp, &farm, &bfso))
		{
			++lim;
			k = 0;
			reset_bfs(&bfso, farm);
			continue;
		}
		search_rev_matrix(&farm->matrix, tmp);
		push_to_ways(&farm->ways, normal_way(tmp), lim, farm);
		reset_bfs(&bfso, farm);
		k++;
	}
	destroy_bfs(&bfso);
	destroy_matrix(farm->matrix, farm->rooms_cnt);
}
