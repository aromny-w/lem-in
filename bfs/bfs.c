/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:26:34 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/07 04:56:14 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	level_up(int **q, int **q1, int size)
{
	free(*q);
	*q = *q1;
	*q1 = queue(size);
}

t_room	*get_linked_room(t_room *room, int **matrix)
{
	t_link *ptr;

	ptr = room->link;
	while (ptr)
	{
		if (ptr->room->visited == 0 && matrix[room->num][ptr->room->num])
			return (ptr->room);
		ptr = ptr->next;
	}
	return (NULL);
}

void	add_dist(int **matrix, int matrix_size, int *q, t_farm *farm)
{
	t_room	*cur;
	t_room	*linked_room;
	int		i;
	int		*q1;

	q1 = queue(matrix_size);
	cur = farm->end;
	cur->visited = 1;
	enqueue(q, cur->num);
	i = 1;
	while (q[2] != 0)
	{
		cur = dequeue(q, farm);
		while ((linked_room = get_linked_room(cur, matrix)) != NULL)
		{
			linked_room->visited = 1;
			linked_room->dist = i;
			enqueue(q1, linked_room->num);
		}
		if (q[2] == 0 && ++i)
			level_up(&q, &q1, matrix_size);
	}
	free(q);
	free(q1);
}

int		check_start_end(t_farm *farm, t_ways *ways)
{
	t_link *ptr;

	ptr = farm->start->link;
	while (ptr)
	{
		if (ptr->room == farm->end)
		{
			ways->dist = 1;
			ways->way = init_way(farm->end);
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

t_ways	*bfs(t_farm *farm)
{
	t_ways	*ways;
	int		matrix_size;
	int		**matrix;
	int		*q;

	ways = NULL;
	ways = init_ways();
	if (check_start_end(farm, ways))
		return (ways);
	matrix_size = get_rooms_count(farm);
	matrix = create_matrix(matrix_size);
	while (1)
	{
		fill_matrix(&matrix, farm);
		q = queue(matrix_size);
		add_dist(matrix, matrix_size, q, farm);
		if (!(add_way(ways, farm)))
			break ;
		reset_matrix(&matrix, matrix_size);
		reset_dist(farm);
	}
	destroy_matrix(matrix, matrix_size);
	return (ways);
}
