/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   islink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:48:16 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/21 21:48:17 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	islink(char *line)
{
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (*line == '-')
		line++;
	if (*line == 'L' || *line == '#')
		return (0);
	while (ft_isalnum(*line) || *line == '_')
		line++;
	if (!*line)
		return (1);
	return (0);
}
