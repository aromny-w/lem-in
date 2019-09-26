/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:19:24 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/26 21:09:36 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ways	*suurballe_bfs(t_farm *farm)
{
	t_ways	*ways;
	int		**matrix;
	int		matrix_size;
	int		*q;

	ways = init_ways();
	matrix_size = get_rooms_count(farm);
	matrix = create_matrix(matrix_size);
	q = queue(matrix_size);
	return (ways);
}

t_ways	*suurballe(t_farm *farm)
{
	t_farm	*split_farm;
	t_ways	*ways;

	split_farm = NULL;
	split_farm = make_split_farm(farm);
	ways = suurballe_bfs(split_farm);
	// TODO del split farm!!!
	return (ways);
}
