/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antsdist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:21:15 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 18:47:48 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	printants(t_ant *ant, int n)
{
	int	i;
	int	check;

	check = 0;
	i = -1;
	while (++i < n)
	{
		if (ant[i].way)
		{
			if (check)
				ft_printf(" ");
			check++;
			ft_printf("L%d-%s", ant[i].number, ant[i].way->room->name);
			if (!ant[i].way->next)
				ant[i].way = ant[i].way->next;
			else
				ant[i].way = ant[i].way->next->next;
		}
	}
	if (!check)
		return (0);
	ft_printf("\n");
	return (1);
}

static void	settruelen(t_path *path, int k)
{
	int	i;

	i = -1;
	while (++i < k)
		path[i].len = path[i].len / 2;
}

static void	setlimits(t_path *path, int k, int ants)
{
	int	i;
	int	threshold;

	threshold = path[0].len;
	while (ants)
	{
		i = -1;
		while (ants && ++i < k)
		{
			if (path[i].len + path[i].limit == threshold)
			{
				path[i].limit++;
				ants--;
			}
		}
		threshold++;
	}
}

static void	writeinput(t_list *input)
{
	while (input)
	{
		ft_putendl(input->content);
		input = input->next;
	}
	ft_putchar('\n');
}

void		antsdist(t_path *path, int k, int ants)
{
	t_ant	ant[ants];
	int		lines;
	int		i;
	int		n;

	ft_memset(ant, 0, sizeof(ant));
	settruelen(path, k);
	setlimits(path, k, ants);
	n = 0;
	lines = path[0].len + path[0].limit;
	while (ants)
	{
		i = -1;
		while (++i < k)
		{
			if (path[i].limit && n < ants)
			{
				ant[n].number = n + 1;
				ant[n++].way = path[i].way->next;
				path[i].limit--;
			}
		}
		if (!printants(ant, ants))
			break ;
	}
}
