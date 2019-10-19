/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 08:53:09 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 13:23:42 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	return (lim + 10);
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
