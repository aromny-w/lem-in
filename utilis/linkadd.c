/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <aromny-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:51:05 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/24 22:52:23 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	linkadd(t_link **link, t_link *new)
{
	new->next = *link;
	*link = new;
}
