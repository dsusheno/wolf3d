/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:13:22 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 19:13:27 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define POS_START_X	2
#define POS_START_Y	2
#define PARAM_CUBE	512

void	ft_map_choose(t_gener *s_gen, t_info *s_inf)
{
	if (s_gen->map_choose == 0)
	{
		s_gen->map_choose = 1;
		s_gen->map = s_gen->map_42;
		s_gen->map_width = s_gen->map_42_w;
		s_gen->map_height = s_gen->map_42_h;
	}
	else if (s_gen->map_choose == 1)
	{
		s_gen->map_choose = 2;
		s_gen->map = s_gen->big_map;
		s_gen->map_width = s_gen->big_map_w;
		s_gen->map_height = s_gen->big_map_h;
	}
	else if (s_gen->map_choose == 2)
	{
		s_gen->map_choose = 0;
		s_gen->map = s_gen->mini_map;
		s_gen->map_width = s_gen->mini_map_w;
		s_gen->map_height = s_gen->mini_map_h;
	}
	s_inf->pos_x = POS_START_X * PARAM_CUBE;
	s_inf->pos_y = POS_START_Y * PARAM_CUBE;
}

void	ft_event(t_gener *s_gen, t_info *s_inf)
{
	if (s_gen->event->type == SDL_QUIT)
		s_gen->quit = 1;
	if (s_gen->event->type == SDL_KEYDOWN)
	{
		if (s_gen->event->key.keysym.sym == SDLK_t)
		{
			if (s_inf->color1_texture2 == 2)
				s_inf->color1_texture2 = 1;
			else if (s_inf->color1_texture2 == 1)
				s_inf->color1_texture2 = 2;
		}
		if (s_gen->event->key.keysym.sym == SDLK_m)
			ft_map_choose(s_gen, s_inf);
	}
}

void	ft_game_action(t_gener *s_gen, t_info *s_inf)
{
	if (s_inf->color1_texture2 == 1)
	{
		ft_sky_color(s_gen);
		ft_floor_color(s_gen);
		ray_casting(s_gen, s_inf);
		draw_mini_map(s_gen, s_inf);
		SDL_UpdateTexture(s_gen->texture, NULL, s_gen->pixels,
			s_gen->s_w * sizeof(Uint32));
		SDL_RenderCopy(s_gen->renderer, s_gen->texture, NULL, NULL);
	}
	else
	{
		ft_floor_color(s_gen);
		SDL_UpdateTexture(s_gen->texture, NULL, s_gen->pixels,
			s_gen->s_w * sizeof(Uint32));
		SDL_RenderCopy(s_gen->renderer, s_gen->texture, NULL, NULL);
		ray_casting(s_gen, s_inf);
		draw_mini_map(s_gen, s_inf);
		SDL_UpdateTexture(s_gen->texture, NULL, s_gen->pixels,
			s_gen->s_w * sizeof(Uint32));
		renderer_mini_map(s_gen, s_inf);
	}
}

void	ft_keystate(t_gener *s, t_info *s_inf)
{
	if (s->keystate[SDL_SCANCODE_LEFT] || s->keystate[SDL_SCANCODE_RIGHT]
		|| s->keystate[SDL_SCANCODE_UP] || s->keystate[SDL_SCANCODE_DOWN]
		|| s->keystate[SDL_SCANCODE_ESCAPE] || s->keystate[SDL_SCANCODE_LALT]
		|| s->keystate[SDL_SCANCODE_T] || s->keystate[SDL_SCANCODE_M])
	{
		SDL_RenderClear(s->renderer);
		if (s->keystate[SDL_SCANCODE_ESCAPE])
			s->quit = 1;
		if (s->keystate[SDL_SCANCODE_LSHIFT] ||
			s->keystate[SDL_SCANCODE_RSHIFT])
			s_inf->pos_speed = 70;
		else
			s_inf->pos_speed = 30;
		if (s->keystate[SDL_SCANCODE_LEFT])
			s_inf->pov += s_inf->pov_speed;
		if (s->keystate[SDL_SCANCODE_RIGHT])
			s_inf->pov -= s_inf->pov_speed;
		if (s->keystate[SDL_SCANCODE_DOWN])
			key_down(s, s_inf);
		if (s->keystate[SDL_SCANCODE_UP])
			key_up(s, s_inf);
		ft_game_action(s, s_inf);
		SDL_RenderPresent(s->renderer);
	}
}

void	sdl_all(t_gener *s_gen, t_info *s_inf)
{
	SDL_Event	event;
	int			angle;

	s_gen->map_choose = 0;
	s_gen->quit = 0;
	s_gen->event = &event;
	image_load(s_gen, s_inf);
	ft_sky_color(s_gen);
	ft_floor_color(s_gen);
	ray_casting(s_gen, s_inf);
	draw_mini_map(s_gen, s_inf);
	SDL_UpdateTexture(s_gen->texture, NULL, s_gen->pixels,
		s_gen->s_w * sizeof(Uint32));
	SDL_RenderCopy(s_gen->renderer, s_gen->texture, NULL, NULL);
	SDL_RenderPresent(s_gen->renderer);
	while (!s_gen->quit)
	{
		SDL_PollEvent(&event);
		s_gen->keystate = SDL_GetKeyboardState(NULL);
		ft_event(s_gen, s_inf);
		ft_keystate(s_gen, s_inf);
	}
	SDL_DestroyTexture(s_gen->texture);
	SDL_DestroyRenderer(s_gen->renderer);
	SDL_DestroyWindow(s_gen->window);
}
