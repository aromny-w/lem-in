/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:00:37 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/21 15:08:19 by aromny-w         ###   ########.fr       */
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

int		move_up(int dist, t_way *way, t_farm *farm, int j)
{
	int	i;

	i = 0;
	while (dist--)
		way = way->next->next;
	(void)farm;
	if (way->ant != 0)
	{
		i = 1;
		if (way->next->next != NULL)
		{
			ans_wr(way->ant, way->next->next->room, j);
			way->next->next->ant = way->ant;
		}
		else
			i = 0;
		way->ant = 0;
	}
	return (i);
}

int		ways_up(t_path *path, int k, t_farm *farm)
{
	int dist;
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < k)
	{
		dist = path[i].len;
		while (dist--)
			if (move_up(dist, path[i].way, farm, ret))
				ret = 1;
		i++;
	}
	return (ret);
}

void ants_move(t_path *path, int k, t_farm *farm)
{
	int		ant;
	int		sw;
	int		j;

	
	ant = 0;
	while (ant < farm->ants)
	{
		sw = ways_up(path, k, farm);
		j = 0;
		path[j].way->ant = ++ant;
		ans_wr(ant, path[j].way->room, sw);
		while (++j < k && (int)(((path[j].len) - (path[j - 1].len)) * j) < farm->ants - ant)
		{
			path[j].way->ant = ++ant;
			ans_wr(ant, path[j].way->room, 1);
		}
		write(1, "\n", 1);
	}
	while (ant)
	{
		ant = ways_up(path, k, farm);
		if (ant)
			write(1, "\n", 1);
	}
}
