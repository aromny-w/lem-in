/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 09:50:50 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/21 10:11:53 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_way(t_way *way)
{
	t_way *ptr;

	ptr = way;
	ft_printf("way: ");
	while (ptr)
	{
		ft_printf("%s ", ptr->room->name);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

void	print_ways(t_ways *ways)
{
	t_ways	*ptr;

	ptr = ways;
	while (ptr && ptr->way)
	{
		print_way(ptr->way);
		ptr = ptr->next;
	}
}

