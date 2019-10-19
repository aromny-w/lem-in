/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_islink_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:45:52 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 15:46:05 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

size_t	namelen2(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line != '-')
		line++;
	if (!*line++)
		return (0);
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}

size_t	namelen1(char *line)
{
	size_t	len;

	len = 0;
	while (ft_isalnum(*line) || *line == '_')
	{
		line++;
		len++;
	}
	return (len);
}
