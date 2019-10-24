/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initfarm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:58:14 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/24 17:07:53 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	initfarm(t_farm *farm)
{
	farm->ants = -1;
	farm->room = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->input = NULL;
	farm->buf = NULL;
	farm->depth = 200;
}
