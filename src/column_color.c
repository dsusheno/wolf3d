/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   column_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:34:26 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/15 16:38:46 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	color_chooser_y(t_info *s_inf)
{
	if ((s_inf->angle >= 90 && s_inf->angle <= 270))
	{
		if (s_inf->color_bool == 1 && s_inf->color == 0xCC3300)
		{
			s_inf->color_bool = 0;
			return ;
		}
		s_inf->color = 0xFFCC33;
		s_inf->color_bool = 1;
	}
	if ((s_inf->angle > -90 && s_inf->angle < 90)
		|| (s_inf->angle > 270 && s_inf->angle < 450))
	{
		if (s_inf->color_bool == 1 && s_inf->color == 0xCC3300)
		{
			s_inf->color_bool = 0;
			return ;
		}
		s_inf->color = 0x00CC66;
		s_inf->color_bool = 1;
	}
}

void	color_chooser_x(t_info *s_inf)
{
	if ((s_inf->angle >= 180 && s_inf->angle <= 360)
		|| (s_inf->angle >= -180 && s_inf->angle <= 0))
	{
		if (s_inf->color_bool == 1 && s_inf->color == 0xFFCC33)
		{
			s_inf->color_bool = 0;
			return ;
		}
		s_inf->color = 0x99FFFF;
		s_inf->color_bool = 1;
	}
	if ((s_inf->angle > 0 && s_inf->angle < 180)
		|| (s_inf->angle > 360 && s_inf->angle < 540))
	{
		if (s_inf->color_bool == 1 && s_inf->color == 0xFFCC33)
		{
			s_inf->color_bool = 0;
			return ;
		}
		s_inf->color = 0xCC3300;
		s_inf->color_bool = 1;
	}
}

void	color_chooser(t_info *s_inf)
{
	if (s_inf->dist_trass_y > s_inf->dist_trass_x)
		color_chooser_y(s_inf);
	else
		color_chooser_x(s_inf);
}

void	draw_column_color(t_gener *s_gen, t_info *s_inf)
{
	while (s_inf->height_point <= s_inf->lower_point)
	{
		if (s_inf->height_point >= 0 && s_inf->height_point <= s_gen->s_h)
			s_gen->pixels[s_inf->height_point
				* s_gen->s_w + s_inf->nb_column] = s_inf->color;
		s_inf->height_point++;
	}
}
