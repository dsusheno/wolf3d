/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:34:39 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/15 16:45:50 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_rotation_down(t_info *s_inf)
{
	s_inf->pos_x -= cos(s_inf->pov * M_PI / 180) * s_inf->pos_speed;
	s_inf->pos_y += sin(s_inf->pov * M_PI / 180) * s_inf->pos_speed;
}

void	ft_rotation_up(t_info *s_inf)
{
	s_inf->pos_x += cos(s_inf->pov * M_PI / 180) * s_inf->pos_speed;
	s_inf->pos_y -= sin(s_inf->pov * M_PI / 180) * s_inf->pos_speed;
}

void	key_down(t_gener *s_gen, t_info *s_inf)
{
	int dist;
	int stop;
	int x;
	int y;

	dist = 0;
	stop = 0;
	while (dist < s_inf->cube)
	{
		x = (s_inf->pos_x - cos(s_inf->pov * M_PI / 180) * s_inf->pos_speed
			- cos(s_inf->pov * M_PI / 180) * dist) / s_inf->cube;
		y = (s_inf->pos_y + sin(s_inf->pov * M_PI / 180) * s_inf->pos_speed
			+ sin(s_inf->pov * M_PI / 180) * dist) / s_inf->cube;
		if (x < 0 || y < 0 || x > s_gen->map_width || y > s_gen->map_height
			|| (s_gen->map[y][x] != 5 && s_gen->map[y][x] != 9
				&& s_gen->map[y][x] != 0))
		{
			stop = 1;
			break ;
		}
		dist++;
	}
	if (stop == 0)
		ft_rotation_down(s_inf);
}

void	key_up(t_gener *s_gen, t_info *s_inf)
{
	int dist;
	int stop;
	int x;
	int y;

	dist = 0;
	stop = 0;
	while (dist < s_inf->cube)
	{
		x = (s_inf->pos_x + cos(s_inf->pov * M_PI / 180) * s_inf->pos_speed
			+ cos(s_inf->pov * M_PI / 180) * dist) / s_inf->cube;
		y = (s_inf->pos_y - sin(s_inf->pov * M_PI / 180) * s_inf->pos_speed
			- sin(s_inf->pov * M_PI / 180) * dist) / s_inf->cube;
		if (x < 0 || y < 0 || x > s_gen->map_width || y > s_gen->map_height
			|| (s_gen->map[y][x] != 5 && s_gen->map[y][x] != 9
				&& s_gen->map[y][x] != 0))
		{
			stop = 1;
			break ;
		}
		dist++;
	}
	if (stop == 0)
		ft_rotation_up(s_inf);
}

void	ft_floor_color(t_gener *s_gen)
{
	int x;
	int y;

	x = 0;
	y = s_gen->s_h / 2;
	while (y < s_gen->s_h)
	{
		while (x < s_gen->s_w)
		{
			s_gen->pixels[y * s_gen->s_w + x] = 0x3C3C3C;
			x++;
		}
		x = 0;
		y++;
	}
}
