/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:19:24 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/27 21:53:34 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	slevel_up(int **q, int **q1, int size)
{
	free(*q);
	*q = *q1;
	*q1 = queue(size);
}

t_room	*sget_linked_room(t_room *room, int **matrix, int matrix_size, t_farm *farm)
{
	int	i;
	t_room	*room_ptr;

	room_ptr = NULL;
	i = -1;
	while (++i < matrix_size)
	{
		if (matrix[room->num][i])
		{
			room_ptr = find_room_by_num(farm, i);
			if (room_ptr && room_ptr->visited == 0)
			 	return (room_ptr);
			if (matrix[room->num][i] == 2 && room_ptr != farm->end)
			{
				farm->again = 1;
				ft_printf("DAVAI_PONOVOY\n");
				suurballe_exclude_link(farm, room->num, i);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	suurable_add_dist(int	**matrix, int matrix_size, int *q, t_farm **farm)
{
	t_room	*cur;
	t_room	*linked_room;
	int		i;
	int		*q1;

	q1 = queue(matrix_size);
	cur = (*farm)->end;
	cur->visited = 1;
	enqueue(q, cur->num);
	i = 1.0;
	while (q[2] != 0)
	{
		cur = dequeue(q, *farm);
		while ((linked_room = sget_linked_room(cur, matrix, matrix_size, *farm)) != NULL)
		{
			linked_room->visited = 1;
			linked_room->dist = i;
			enqueue(q1, linked_room->num);
		}
		if ((*farm)->again)
			break;
		if (q[2] == 0 && ++i)
			slevel_up(&q, &q1, matrix_size);
	}
	free(q);
	free(q1);
}

void		suurballe_bfs(t_farm *farm, int **matrix, int matrix_size)
{
	int		*q;

	print_matrix(matrix, matrix_size);
	q = queue(matrix_size);
	suurable_add_dist(matrix, matrix_size, q, &farm);
}

t_ways	*suurballe(t_farm *farm)
{
	t_farm	*split_farm;
	t_ways	*ways;
	int		**matrix;
	int		matrix_size;

	split_farm = NULL;
	split_farm = make_split_farm(farm);
	ways = init_ways();
	matrix_size = get_rooms_count(split_farm);
	matrix = create_matrix(matrix_size);
	while (1)
	{
		fill_matrix(&matrix, split_farm);
		suurballe_bfs(split_farm, matrix, matrix_size);
		if (!(add_way(ways, split_farm)))
			break;
		print_ways(ways);
		// suurballe_reverse_links(split_farm, ways);
		//reset_dist(split_farm);	
	}
	destroy_matrix(matrix, matrix_size);
	return (ways);
}
