/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:30:22 by aromny-w          #+#    #+#             */
/*   Updated: 2019/10/19 17:22:37 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	terminate(int status)
{
	if (status == -1)
		ft_putstr_fd("ERROR\n", 2);
	if (status != -1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}
