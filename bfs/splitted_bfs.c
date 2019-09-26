/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitted_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:19:24 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/26 20:24:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


t_ways	*splitted_bfs(t_farm *farm)
{
	t_ways	*ways;
	int		matrix_size;
	int		**matrix;
	int		*q;

	ways = NULL;
	ways = init_ways();
	matrix_size = get_rooms_count(farm);
	matrix = create_matrix(matrix_size);
	fill_matrix(&matrix, farm);
	print_matrix(matrix, matrix_size);
	ft_printf("HELLO");
	q = queue(matrix_size);
	//add_dist(matrix, matrix_size, q, farm);
	add_way(ways, farm);
	debug_print_rooms(farm);
	return (ways);
}
