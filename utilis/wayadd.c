/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wayadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:56:39 by aromny-w          #+#    #+#             */
/*   Updated: 2019/09/14 21:56:40 by aromny-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	wayadd(t_way **way, t_way *new)
{
	new->next = *way;
	*way = new;
}
