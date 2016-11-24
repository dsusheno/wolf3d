/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:01:42 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 21:01:44 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ray_casting(t_gener *s_gen, t_info *s_inf)
{
	double angle_p;
	double angle_max;

	if (s_inf->pov >= 360)
		s_inf->pov -= 360;
	if (s_inf->pov < 0)
		s_inf->pov += 360;
	s_inf->angle = (s_inf->pov - (s_inf->fov / 2));
	s_inf->angle_r = s_inf->angle * M_PI / 180;
	s_inf->param_line = 0.5 * s_gen->s_w / tan(0.5 * s_inf->fov * M_PI / 180);
	s_inf->nb_column = s_gen->s_w - 1;
	angle_p = s_inf->fov / s_gen->s_w;
	angle_max = (s_inf->pov + (s_inf->fov / 2));
	while (s_inf->angle <= angle_max && s_inf->nb_column >= 0)
	{
		trass_y(s_gen, s_inf);
		trass_x(s_gen, s_inf);
		draw_column(s_gen, s_inf);
		s_inf->angle += angle_p;
		s_inf->nb_column -= 1;
		s_inf->angle_r = s_inf->angle * M_PI / 180;
	}
}

void	ray_cast_y(t_gener *s_gen, t_info *s_inf)
{
	if ((s_inf->angle >= 0 && s_inf->angle <= 180)
		|| (s_inf->angle >= 360 && s_inf->angle <= 540))
	{
		s_inf->y_pos_ry = (int)(s_inf->pos_y / s_inf->cube) * s_inf->cube - 1;
		s_inf->y_dist = -(s_inf->cube);
	}
	else
	{
		s_inf->y_pos_ry = (int)(s_inf->pos_y / s_inf->cube)
		* s_inf->cube + s_inf->cube;
		s_inf->y_dist = s_inf->cube;
	}
	s_inf->x_pos_ry = s_inf->pos_x + (s_inf->pos_y - s_inf->y_pos_ry)
	/ tan(s_inf->angle_r);
	s_inf->x_dist = s_inf->cube / tan(s_inf->angle_r);
	if (s_inf->x_dist > 0 && ((s_inf->angle >= 90 && s_inf->angle <= 270)
		|| (s_inf->angle >= -270 && s_inf->angle <= -90)))
		s_inf->x_dist = -s_inf->x_dist;
	else if (s_inf->x_dist < 0 && ((s_inf->angle >= -90 && s_inf->angle <= 90)
		|| (s_inf->angle >= 270 && s_inf->angle <= 450)))
		s_inf->x_dist = -s_inf->x_dist;
}

void	ray_cast_x(t_gener *s_gen, t_info *s_inf)
{
	double angle_abs;

	if (s_inf->angle <= 90 || s_inf->angle >= 270)
	{
		s_inf->x_pos_rx = (int)(s_inf->pos_x / s_inf->cube)
		* s_inf->cube + s_inf->cube;
		s_inf->x_dist = s_inf->cube;
	}
	else
	{
		s_inf->x_pos_rx = (int)(s_inf->pos_x / s_inf->cube) * s_inf->cube - 1;
		s_inf->x_dist = -(s_inf->cube);
	}
	s_inf->y_pos_rx = s_inf->pos_y + (s_inf->pos_x - s_inf->x_pos_rx)
	* tan(s_inf->angle_r);
	s_inf->y_dist = s_inf->cube * tan(s_inf->angle_r);
	if (s_inf->y_dist > 0 && ((s_inf->angle >= 0 && s_inf->angle <= 180)
		|| (s_inf->angle >= 360 && s_inf->angle <= 540)))
		s_inf->y_dist = -s_inf->y_dist;
	else if (s_inf->y_dist < 0 && ((s_inf->angle >= 180 && s_inf->angle <= 360)
		|| (s_inf->angle >= -180 && s_inf->angle <= 0)))
		s_inf->y_dist = -s_inf->y_dist;
}

void	trass_y(t_gener *s_gen, t_info *s_inf)
{
	int	round_x;
	int round_y;

	ray_cast_y(s_gen, s_inf);
	round_y = (int)(s_inf->y_pos_ry / s_inf->cube);
	round_x = (int)(s_inf->x_pos_ry / s_inf->cube);
	while (round_y >= 0 && round_y < s_gen->map_height
		&& round_x >= 0 && round_x < s_gen->map_width
		&& s_gen->map[round_y][round_x] == 0)
	{
		s_inf->x_pos_ry += s_inf->x_dist;
		s_inf->y_pos_ry += s_inf->y_dist;
		round_y = (int)(s_inf->y_pos_ry / s_inf->cube);
		round_x = (int)(s_inf->x_pos_ry / s_inf->cube);
	}
	if (round_y >= 0 && round_y < s_gen->map_height
		&& round_x >= 0 && round_x < s_gen->map_width)
		s_inf->nb_texture_y = s_gen->map[round_y][round_x];
	s_inf->dist_trass_y = sqrt((s_inf->pos_x - s_inf->x_pos_ry)
		* (s_inf->pos_x - s_inf->x_pos_ry)
		+ (s_inf->pos_y - s_inf->y_pos_ry) * (s_inf->pos_y - s_inf->y_pos_ry));
}

void	trass_x(t_gener *s_gen, t_info *s_inf)
{
	int	round_x;
	int round_y;

	ray_cast_x(s_gen, s_inf);
	round_y = (int)(s_inf->y_pos_rx / s_inf->cube);
	round_x = (int)(s_inf->x_pos_rx / s_inf->cube);
	while (round_y >= 0 && round_y < s_gen->map_height
		&& round_x >= 0 && round_x < s_gen->map_width
		&& s_gen->map[round_y][round_x] == 0)
	{
		s_inf->x_pos_rx += s_inf->x_dist;
		s_inf->y_pos_rx += s_inf->y_dist;
		round_y = (int)(s_inf->y_pos_rx / s_inf->cube);
		round_x = (int)(s_inf->x_pos_rx / s_inf->cube);
	}
	if (round_y >= 0 && round_y < s_gen->map_height
		&& round_x >= 0 && round_x < s_gen->map_width)
		s_inf->nb_texture_x = s_gen->map[round_y][round_x];
	s_inf->dist_trass_x = sqrt((s_inf->pos_x - s_inf->x_pos_rx)
		* (s_inf->pos_x - s_inf->x_pos_rx)
		+ (s_inf->pos_y - s_inf->y_pos_rx) * (s_inf->pos_y - s_inf->y_pos_rx));
}
