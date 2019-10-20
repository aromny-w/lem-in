/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:08:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/20 21:33:15 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# include "libft.h"
# include "lem_in.h"
# include "SDL.h"
# include <math.h>

# define SCREEN_WIDTH 1680
# define SCREEN_HEIGHT 1680
# define START_X 50
# define START_Y 50

typedef	struct		s_ants_renderer
{
	int						x1;
	int						y1;
	int						x2;
	int						y2;
	int						speed_x;
	int						speed_y;
	int						x;
	int						y;
	int						w;
	int						h;
	struct	s_ants_renderer	*next;
	
}					t_ants_renderer;

typedef struct		s_step
{
	char				*step;
	int					running;
	int					reverse;
	int					done;
	t_ants_renderer		*aren;
	struct s_step		*next;
	struct s_step		*prev;
}					t_step;

typedef struct 		s_visu_link
{
	t_room				*room1;
	t_room				*room2;
	struct s_visu_link	*next;
}					t_visu_link;

typedef struct		s_env
{
	int				ants;
	t_room			*room;
	t_room			*start;
	t_room			*end;
	t_visu_link		*link;
	int				rooms_cnt;
	int				links_cnt;

	t_step			*step;
	
	int				max_x_coord;
	int				max_y_coord;
	int				min_x_coord;
	int				min_y_coord;
	int				width_persize;
	int				height_persize;
	int				room_radius;

	int				run;
	SDL_Window		*window;
	int				delay;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	SDL_Event		e;
	int				x;
	int				y;
	int				camera_speed;

	int				key_up;
	int				key_down;
	int				key_left;
	int				key_right;
	int				key_s;
	int				key_plus;
	int				key_minus;
}					t_env;

typedef struct		s_circle_drawer
{
	double			x;
	double			y;
	double			cx;
	double			cy;
	double			dy;
	double			dx;
	int				nx;
	int 			ny;
	int				radius;
	double			error;
}					t_circle_drawer;


void				init_sdl(t_env *env);
void				destroy_sdl(t_env *env);
void				handle_event(t_env *env);
void				do_tick(t_env *env);
void				visu_reader(t_env *env, char *line, int fd);
int					visu_readcommand(t_env *env, int fd, char **line);
void				set_maxmincoords(t_env *env, t_point point);

void				render(t_env *env);
void				render_rooms(t_env *env);
void				render_links(t_env *env);

void				set_pixel(SDL_Renderer *rend, int r, int g, int b);
void				sdl_draw_circle(SDL_Renderer *rend, int x, int y, int radius);

/*
***
*/
int					visu_isantnbr(char *line);
int					visu_is_room(char *line, t_room *room);
int					visu_islink(char *line, t_room *room);
int					visu_iscommand(char *line);
int					visu_iscomment(char *line);
void				visu_setroom(char *line, t_room **room, t_env *env);

void				count_ants(t_env *env);

void				addnewlink(t_env *env,t_visu_link **link,
						t_visu_link *new);

int					isname(char **line, t_room *room);
size_t				namelen(char *line);
int					iscoord1(char **line);
int					iscoord2(char **line);

size_t				namelen2(char *line);
size_t				namelen1(char *line);


#endif
