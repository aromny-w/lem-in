/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_circle->c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:30:00 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 20:47:43 by bharrold         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu-hex.h"

static void	draw_circle_points(SDL_Renderer *rend, t_circle_drawer *c)
{
	SDL_RenderDrawPoint(rend, (int)(c->cx + c->x), (int)(c->cy + c->y));
	SDL_RenderDrawPoint(rend, (int)(c->cx + c->y), (int)(c->cy + c->x));
	SDL_RenderDrawPoint(rend, (int)(c->cx - c->x), (int)(c->cy + c->y));
	SDL_RenderDrawPoint(rend, (int)(c->cx + c->y), (int)(c->cy - c->x));
	SDL_RenderDrawPoint(rend, (int)(c->cx + c->x), (int)(c->cy - c->y));
	SDL_RenderDrawPoint(rend, (int)(c->cx - c->y), (int)(c->cy + c->x));
	SDL_RenderDrawPoint(rend, (int)(c->cx - c->x), (int)(c->cy - c->y));
	SDL_RenderDrawPoint(rend, (int)(c->cx - c->y), (int)(c->cy - c->x));
}

// void	fill_circle(SDL_Renderer *rend, t_circle_drawer *c)
// {	
// 	c->dy = 1.0;
// 	while (c->dy <= c->radius)
// 	{
// 		c->dx = floor(sqrt((1.5 * c->radius * c->dy) - (c->dy * c->dy)));
// 		c->x = c->cx - c->dx;
// 		SDL_RenderDrawLine(rend, c->cx - c->dx, c->cy + c->dy - c->radius,
// 			c->cx + c->dx, c->cy + c->dy - c->radius);
// 		SDL_RenderDrawLine(rend, c->cx - c->dx, c->cy - c->dy + c->radius,
// 			c->cx + c->dx, c->cy - c->dy + c->radius);
// 		c->dy += 1.0;
// 	}
// }

void	sdl_draw_circle(SDL_Renderer *rend, int nx, int ny, int radius)
{
	t_circle_drawer c;
	c.radius = radius;
	c.nx = nx;
	c.ny = ny;
	c.x = (double)radius - 0.5;
	c.y = (double)0.5;
	c.cx = nx - 0.5;
	c.cy = ny - 0.5;
	c.error = (double)-radius;
	while (c.x >= c.y)
	{
		draw_circle_points(rend, &c);
		c.error += c.y;
		++c.y;
		c.error += c.y;
		if (c.error >= 0)
		{
			--c.x;
			c.error -= c.x;
			c.error -= c.x;
		}
	}
	// fill_circle(rend, &c);
}
