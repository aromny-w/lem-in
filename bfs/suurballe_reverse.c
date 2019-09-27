/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:56:04 by bharrold          #+#    #+#             */
/*   Updated: 2019/09/27 20:37:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*suurballe_get_last_way(t_ways *ways)
{
	t_ways *ptr;

	ptr = ways;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if (!ptr)
		return (NULL);
	return (ptr->way);
}

void	suurballe_delete_link(t_room *r1, t_room *r2)
{
	t_link	*ptr;
	t_link	*cur;

	ptr = r1->link;
	cur = NULL;
	while (ptr && ptr->next)
	{
		if (ptr->room == r2 || ptr->next->room == r2)
		{
			cur = (ptr->room == r2) ? ptr : ptr->next;
			break;
		}
		ptr = ptr->next;
	}
	if (cur == NULL)
		ft_printf("SUUUKA");
	if (ptr->next)
		ptr->next = cur->next;
	free(cur);
}

void	suurballe_add_link(t_room *r1, t_room *r2)
{
	t_link *new;

	new = linknew(r2, 1);
	new->visited = 1;
	new->excluded = 0;
	linkadd(&(r1->link), new);
}

void	suurballe_swap_links(t_farm *farm, t_room *r1, t_room *r2)
{
	// t_room	*tmp;
	(void)farm;
	ft_printf("%s %d %d | %s %d %d\n", r1->name, r1->in, r1->out,
		r2->name, r2->in, r2->out);
	suurballe_delete_link(r1, r2);
	suurballe_add_link(r2, r1);
}

void	suurballe_reverse_links(t_farm *farm, t_ways *ways)
{
	t_way	*last_way;
	t_way	*ptr;

	last_way = suurballe_get_last_way(ways);
	(void)farm;
	if (!last_way)
		return ;
	// ft_printf(" >> SUURBALLE REVERSE LINKS << \n");
	//print_way(last_way);
	ptr = last_way;
	suurballe_swap_links(farm, farm->start, ptr->room);
	while (ptr->next)
	{
		suurballe_swap_links(farm, ptr->room, ptr->next->room);
		ptr = ptr->next;
	}
	suurballe_swap_links(farm, ptr->room, farm->end);
}
