/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:08:30 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 18:08:34 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_skybox(t_gener *s_gen, t_info *s_inf)
{
	SDL_Rect	src;
	SDL_Rect	dst;
	double		angle;

	if (s_inf->angle > 360)
		angle = s_inf->angle - 360;
	else if (s_inf->angle > 0)
		angle = s_inf->angle;
	else
		angle = s_inf->angle + 360;
	dst.x = s_inf->nb_column;
	dst.y = 0;
	dst.w = 1;
	dst.h = s_gen->s_h / 2;
	src.x = angle * 5110 / 360;
	src.y = 0;
	src.w = 1;
	src.h = s_gen->s_h / 2;
	SDL_RenderCopy(s_gen->renderer, s_inf->skybox, &src, &dst);
}

void	ft_sky_color(t_gener *s_gen)
{
	int x;
	int y;
	int y_max;

	x = 0;
	y = 0;
	y_max = s_gen->s_h / 2;
	while (y < y_max)
	{
		while (x < s_gen->s_w)
		{
			s_gen->pixels[y * s_gen->s_w + x] = 0x0888ae;
			x++;
		}
		x = 0;
		y++;
	}
}
