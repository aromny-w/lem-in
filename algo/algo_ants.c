/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:18:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 22:05:11 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ans_wr(int i, t_room *room, char fl)
{
	char	*ant;

	ant = ft_itoa(i);
	if (fl)
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putstr(ant);
	write(1, "-", 1);
	ft_putstr(room->name);
	free(ant);
}

void	all_ants_one_way(t_farm *farm, t_ways *ways)
{
	int ant;

	ant = 1;
	ans_wr(ant, ways->way->room, 0);
	while (++ant <= farm->ants)
	{
		ans_wr(ant, ways->way->room, 1);
	}
	write(1, "\n", 1);
}

int		move_up(int dist, t_way *way, t_farm *farm, int j)
{
	int	i;

	i = 0;
	while (dist--)
		way = way->next;
	(void)farm;
	if (way->ant != 0)
	{
		i = 1;
		if (way->next != NULL)
		{
			ans_wr(way->ant, way->next->room, j);
			way->next->ant = way->ant;
		}
		else
			i = 0;
		way->ant = 0;
	}
	return (i);
}

int		ways_up(t_ways *ways, t_farm *farm)
{
	int dist;
	int i;

	i = 0;
	while (ways)
	{
		dist = ways->dist;
		while (dist--)
			if (move_up(dist, ways->way, farm, i))
				i = 1;
		ways = ways->next;
	}
	return (i);
}

void	lets_go(t_farm *farm, t_ways *ways, int ants, t_ways *begin)
{
	int		ant;
	int		sw;
	int		i;

	ant = 0;
	while (ant < ants)
	{
		i = 1;
		sw = ways_up(ways, farm);
		ways = begin;
		ways->way->ant = ++ant;
		ans_wr(ant, ways->way->room, sw);
		while (ways->next && ((ways->next->dist - begin->dist) * i) - 1 < ants - ant)
		{
			i++;
			ways = ways->next;
			ways->way->ant = ++ant;
			ans_wr(ant, ways->way->room, 1);
		}
		write(1, "\n", 1);
	}
	while (ant)
	{
		ant = ways_up(begin, farm);
		if (ant)
			write(1, "\n", 1);
	}
}
