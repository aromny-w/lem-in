/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu-hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:08:29 by bharrold          #+#    #+#             */
/*   Updated: 2019/10/19 16:45:49 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H

# include "libft.h"
# include "lem_in.h"
# include "SDL.h"

# define SCREEN_WIDTH 1680
# define SCREEN_HEIGHT 1000

typedef struct		s_step
{
	char				*step;
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
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*surface;
	SDL_Event		e;
	int				run;
	int				delay;
	int				ants;
	t_room			*room;
	t_visu_link		*link;
	t_step			*step;
}					t_env;

void				init_sdl(t_env *env);
void				destroy_sdl(t_env *env);
void				handle_event(t_env *env);
void				render(t_env *env);
void				visu_reader(t_env *env, char *line);

/*
***
*/
int					visu_isantnbr(char *line);
int					visu_is_room(char *line, t_room *room);
int					visu_islink(char *line, t_room *room);
int					visu_iscommand(char *line);
int					visu_iscomment(char *line);

int					isname(char **line, t_room *room);
size_t				namelen(char *line);
int					iscoord1(char **line);
int					iscoord2(char **line);

size_t				namelen2(char *line);
size_t				namelen1(char *line);

#endif
