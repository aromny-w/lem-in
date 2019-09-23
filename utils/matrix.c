/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:45:07 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/23 19:07:43 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		**create_matrix(int size)
{
	int		**matrix;
	int		i;
	int		j;

	matrix = (int**)malloc(sizeof(int*) * (size + 1));
	i = -1;
	while (++i < size)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (size + 1));
		j = -1;
		while (++j < size)
			matrix[i][j] = 0;
	}
	return (matrix);
}

void	destroy_matrix(int **matrix, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
}

void	fill_matrix_start_end(int ***matrix, t_farm *farm)
{
	t_link	*ptr;

	ptr = farm->start->link;
	while(ptr)
	{
		(*matrix)[farm->start->num][ptr->room->num] = 1;
		ptr = ptr->next;
	}
	ptr = farm->end->link;
	while (ptr)
	{
		(*matrix)[farm->end->num][ptr->room->num] = 1;
		ptr = ptr->next;
	}
}

void	fill_matrix(int ***matrix, t_farm *farm)
{
	t_link *ptr;
	t_room *room_ptr;

	fill_matrix_start_end(matrix, farm);
	room_ptr = farm->room;
	while (room_ptr)
	{
		if (room_ptr == farm->start || room_ptr == farm->end)
		{
			room_ptr = room_ptr->next;
			continue;
		}
		ptr = room_ptr->link;
		while (ptr)
		{
			if (!(ptr->room->excluded || room_ptr->excluded))
				(*matrix)[room_ptr->num][ptr->room->num] = 1;
			ptr = ptr->next;
		}
		room_ptr = room_ptr->next;
	}
}

void	print_matrix(int **matrix, int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			ft_printf("%5d ", matrix[i][j]);
		ft_printf("\n");
	}
}
