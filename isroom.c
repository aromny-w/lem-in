/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isroom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:47:09 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 21:47:10 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	isroom(char *line)
{
	int	name;
	int	x;
	int	y;

	name = 0;
	x = 0;
	y = 0;
	if (*line == 'L' || *line == '#')
		return (0);
	while ((ft_isalnum(*line) || *line == '_') && (name = 1))
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line) && (x = 1))
		line++;
	if (*line == ' ')
		line++;
	while (ft_isdigit(*line) && (y = 2))
		line++;
	if (!*line && (name && x && y))
		return (1);
	return (0);
}
