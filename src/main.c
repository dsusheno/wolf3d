/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:57:13 by dsusheno          #+#    #+#             */
/*   Updated: 2016/05/25 16:57:17 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define SCREEN_W		1024
#define SCREEN_H		800
#define POS_START_X		2
#define POS_START_Y		2
#define PARAM_FOV		66
#define PARAM_CUBE		512
#define PARAM_POV		0
#define SPEED_ROTAT		3
#define DEPLACE_SPEED	50

void	dec_info(t_info *s)
{
	s->pos_x = POS_START_X * PARAM_CUBE;
	s->pos_y = POS_START_Y * PARAM_CUBE;
	s->pov = PARAM_POV;
	s->fov = PARAM_FOV;
	s->pov_speed = SPEED_ROTAT;
	s->pos_speed = DEPLACE_SPEED;
	s->angle = 0;
	s->angle_r = 0;
	s->y_pos_rx = 0;
	s->x_pos_rx = 0;
	s->y_pos_ry = 0;
	s->x_pos_ry = 0;
	s->y_dist = 0;
	s->x_dist = 0;
	s->dist_trass_x = 0;
	s->dist_trass_y = 0;
	s->cube = PARAM_CUBE;
	s->nb_column = 0;
	s->param_line = 0;
	s->nb_texture_y = 0;
	s->nb_texture_x = 0;
	s->nb_texture_r = 0;
	s->color_bool = 0;
	s->color1_texture2 = 1;
}

int		sdl_start(t_gener *s_gen)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("Échec de l'initialisation de la SDL\n");
		return (-1);
	}
	s_gen->window = SDL_CreateWindow("Wolf3D", 100,
		100,
		s_gen->s_w,
		s_gen->s_h,
		SDL_WINDOW_SHOWN);
	s_gen->renderer = SDL_CreateRenderer(s_gen->window, -1,
		SDL_RENDERER_PRESENTVSYNC);
	s_gen->texture = SDL_CreateTexture(s_gen->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC,
		s_gen->s_w, s_gen->s_h);
	s_gen->pixels = ft_memalloc(sizeof(Uint32) *
		(s_gen->s_w * s_gen->s_h));
	ft_bzero(s_gen->pixels, s_gen->s_w * s_gen->s_h * sizeof(Uint32));
	return (1);
}

void	ft_error(char *file)
{
	ft_putstr("Wolf3D: ");
	ft_putstr(file);
	perror(" ");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_gener		s_gen;
	t_info		s_inf;

	ft_putstrn("M - change Map");
	ft_putstrn("T - ON/OFF texture");
	ft_putstrn("Shift - to run");
	dec_info(&s_inf);
	s_gen.s_h = SCREEN_H;
	s_gen.s_w = SCREEN_W;
	sdl_start(&s_gen);
	maps_creation(&s_gen);
	sdl_all(&s_gen, &s_inf);
	SDL_Quit();
	return (0);
}
