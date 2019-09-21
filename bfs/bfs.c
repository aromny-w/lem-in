/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:26:34 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 04:48:32 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways	*bfs (t_farm *farm)
{
	t_ways	*ways;
	int		matrix_size;
	int		**matrix;

	ways = init_ways();
	matrix_size = get_rooms_count(farm);
	ft_printf("ROOMS CNT = %d\n", matrix_size);
	matrix = create_matrix(matrix_size);
	fill_matrix(&matrix, farm);
	print_matrix(matrix, matrix_size);
	return (ways);
}
