/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:20:12 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 20:21:26 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

void set_pixel(SDL_Renderer *rend, int r, int g, int b)
{
	SDL_SetRenderDrawColor(rend, r,g,b, 0xFF);
}
