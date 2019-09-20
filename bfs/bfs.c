/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:26:34 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 01:43:24 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "t_rooms_queue.h"


// t_path		algo_bgs(t_rooms_queue *queue, t_farm *farm, t_path *path)
// {
// 	if (peek(queue) == farm->end)
// 	{
// 		return ();
// 	}
// }

t_ways	*bfs (t_farm *farm)
{
	t_ways *ways;
	int		matrix_size;
	
	ways = init_ways();
	matrix_size = get_rooms_count(farm);
	ft_printf("ROOMS CNT = %d\n", matrix_size);
	return (ways);
}