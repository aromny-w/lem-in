/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:38:23 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 18:49:37 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	writeinput(t_list *input)
{
	while (input)
	{
		ft_putendl(input->content);
		input = input->next;
	}
	ft_putchar('\n');
}

static int		linecount(int *len, int k, int ants)
{
	int	threshold;
	int	i;

	threshold = len[0];
	while (ants)
	{
		i = -1;
		while (ants && ++i < k)
		{
			if (len[i] == threshold)
			{
				len[i]++;
				ants--;
			}
		}
		threshold++;
	}
	return (len[0]);
}

static int		brakingsystem(t_path *curr, t_path *prev, int k, int ants)
{
	int	i;
	int	len_curr[k];
	int	len_prev[k - 1];

	if (k == 1)
		return (1);
	i = -1;
	while (++i < k)
		len_curr[i] = curr[i].len / 2;
	i = -1;
	while (++i < k - 1)
		len_prev[i] = prev[i].len / 2;
	if (linecount(len_prev, k - 1, ants) < linecount(len_curr, k, ants))
	{
		free(curr);
		return (0);
	}
	return (1);
}

void			solvefarm(t_farm farm, size_t max)
{
	t_path	*path[1 + max];
	size_t	k;

	k = 0;
	path[k] = NULL;
	splitrooms(&farm.room, farm.start, farm.end);
	while (++k <= max)
	{
		if (!(path[k] = getpaths(&farm, path[k - 1], k)) ||
		!brakingsystem(path[k], path[k - 1], k, farm.ants))
			break ;
	}
	if (k != 1)
	{
		writeinput(farm.input);
		antsdist(path[k - 1], k - 1, farm.ants);
	}
	destroyfarm(&farm, path, k);
}
