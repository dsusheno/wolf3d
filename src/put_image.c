/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:59:07 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 20:59:09 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_image_wall(SDL_Texture *image, t_gener *s_gen, t_info *s_inf)
{
	SDL_Rect src;
	SDL_Rect dst;

	dst.x = s_inf->nb_column;
	dst.y = s_inf->height_point;
	dst.w = 1;
	dst.h = s_inf->lower_point - s_inf->height_point;
	src.x = s_inf->wall_pos % s_inf->cube;
	src.y = 0;
	src.w = 1;
	src.h = s_inf->cube;
	SDL_RenderCopy(s_gen->renderer, image, &src, &dst);
}

void	put_image_wall_got(SDL_Texture *image, t_gener *s_gen, t_info *s_inf)
{
	SDL_Rect src;
	SDL_Rect dst;

	dst.x = s_inf->nb_column;
	dst.y = s_inf->height_point;
	dst.w = 1;
	dst.h = s_inf->lower_point - s_inf->height_point;
	src.x = s_inf->wall_pos % 982;
	src.y = 0;
	src.w = 1;
	src.h = 506;
	SDL_RenderCopy(s_gen->renderer, image, &src, &dst);
}

void	put_image_wall_64(SDL_Texture *image, t_gener *s_gen, t_info *s_inf)
{
	SDL_Rect src;
	SDL_Rect dst;

	dst.x = s_inf->nb_column;
	dst.y = s_inf->height_point;
	dst.w = 1;
	dst.h = s_inf->lower_point - s_inf->height_point;
	src.x = (s_inf->wall_pos * 64 / 512) % 64;
	src.y = 0;
	src.w = 1;
	src.h = 64;
	SDL_RenderCopy(s_gen->renderer, image, &src, &dst);
}

void	image_load(t_gener *s, t_info *s_inf)
{
	s_inf->image_m25 = IMG_LoadTexture(s->renderer, "./img/map1/m-025.jpg");
	s_inf->image_m01 = IMG_LoadTexture(s->renderer, "./img/map1/m-001.jpg");
	s_inf->image_m13 = IMG_LoadTexture(s->renderer, "./img/map1/m-013.jpg");
	s_inf->image_m07 = IMG_LoadTexture(s->renderer, "./img/map1/m-007.jpg");
	s_inf->image_gofr1 = IMG_LoadTexture(s->renderer, "./img/GOT/gofr1.png");
	s_inf->image_gofr2 = IMG_LoadTexture(s->renderer, "./img/GOT/gofr2.png");
	s_inf->image_door_in = IMG_LoadTexture(s->renderer, "./img/door3.png");
	s_inf->skybox = IMG_LoadTexture(s->renderer, "./img/skybox.jpg");
	s_inf->image_wall_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/wall.png");
	s_inf->image_door_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/door.png");
	s_inf->image_wall_o_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/wall_o.png");
	s_inf->image_wall_g_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/wall_g.png");
	s_inf->image_door_wall_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/door_wall.png");
	s_inf->image_wall_gray_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/wall_gray.png");
	s_inf->image_wall_r_wolf =
	IMG_LoadTexture(s->renderer, "./img/wolf/wall_r.png");
}

void	renderer_mini_map(t_gener *s_gen, t_info *s_inf)
{
	SDL_Rect	src;
	SDL_Rect	dst;
	int			y_size;
	int			x_size_wall;

	x_size_wall = 150 / s_gen->map_width;
	y_size = x_size_wall * s_gen->map_height;
	dst.x = 20;
	dst.y = s_gen->s_h - 20 - y_size;
	dst.w = s_gen->map_width * x_size_wall;
	dst.h = y_size;
	src.x = 20;
	src.y = s_gen->s_h - 20 - y_size;
	src.w = s_gen->map_width * x_size_wall;
	src.h = y_size;
	SDL_RenderCopy(s_gen->renderer, s_gen->texture, &src, &dst);
}
