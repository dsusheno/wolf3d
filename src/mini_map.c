/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:58:03 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 20:58:06 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_back_mini(t_gener *s_gen, t_info *s_inf)
{
	int y_size;
	int x_size_wall;
	int y;
	int x;

	x_size_wall = 150 / s_gen->map_width;
	y_size = x_size_wall * s_gen->map_height;
	x = 0;
	y = s_gen->s_h - 20 - y_size;
	while (y < s_gen->s_h - 20)
	{
		while (x < x_size_wall * s_gen->map_width)
		{
			s_gen->pixels[y * s_gen->s_w + (x + 20)] = 0x808080;
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_wall_cord(t_gener *s_gen, t_info *s_inf, int y, int x)
{
	int y_pix;
	int x_pix;
	int y_pix_last;
	int x_pix_last;
	int size_wall;

	size_wall = 150 / s_gen->map_width;
	y_pix = size_wall * y + s_gen->s_h - 20 - (size_wall * s_gen->map_height);
	x_pix = size_wall * x + 20;
	y_pix_last = y_pix + size_wall;
	x_pix_last = x_pix + size_wall;
	while (y_pix < y_pix_last)
	{
		while (x_pix < x_pix_last)
		{
			s_gen->pixels[y_pix * s_gen->s_w + x_pix] = 0x000000;
			x_pix++;
		}
		x_pix = size_wall * x + 20;
		y_pix++;
	}
}

void	draw_mini_wall(t_gener *s_gen, t_info *s_inf)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < s_gen->map_height)
	{
		while (x < s_gen->map_width)
		{
			if (s_gen->map[y][x])
				draw_wall_cord(s_gen, s_inf, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_mini_position(t_gener *s_gen, t_info *s_inf)
{
	double	dif;
	int		pos_mini_x;
	int		pos_mini_y;
	int		size_wall;
	int		size_y_mini;

	size_wall = 150 / s_gen->map_width;
	size_y_mini = size_wall * s_gen->map_height;
	dif = s_inf->cube / size_wall;
	pos_mini_x = s_inf->pos_x / dif + 20;
	pos_mini_y = s_gen->s_h - 20 - size_y_mini + s_inf->pos_y / dif;
	s_gen->pixels[pos_mini_y * s_gen->s_w + pos_mini_x] = 0xFFFFFF;
	s_gen->pixels[(pos_mini_y + 1) * s_gen->s_w + pos_mini_x] = 0xFFFFFF;
	s_gen->pixels[pos_mini_y * s_gen->s_w + (pos_mini_x + 1)] = 0xFFFFFF;
	s_gen->pixels[(pos_mini_y + 1) * s_gen->s_w + (pos_mini_x + 1)] = 0xFFFFFF;
}

void	draw_mini_map(t_gener *s_gen, t_info *s_inf)
{
	draw_back_mini(s_gen, s_inf);
	draw_mini_wall(s_gen, s_inf);
	draw_mini_position(s_gen, s_inf);
}
