/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:45:07 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/26 20:49:37 by bharrold         ###   ########.fr       */
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

void	fill_matrix(int ***matrix, t_farm *farm)
{
	t_link *ptr;
	t_room *room_ptr;

	room_ptr = farm->room;
	while (room_ptr)
	{
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
