/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:19:47 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/15 16:39:53 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_column_image2(t_gener *s_gen, t_info *s_inf)
{
	if (s_inf->nb_texture_r == 8)
		put_image_wall_64(s_inf->image_wall_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 9)
		put_image_wall_64(s_inf->image_door_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 10)
		put_image_wall_64(s_inf->image_wall_o_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 11)
		put_image_wall_64(s_inf->image_wall_g_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 12)
		put_image_wall_64(s_inf->image_door_wall_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 13)
		put_image_wall_64(s_inf->image_wall_gray_wolf, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 14)
		put_image_wall_64(s_inf->image_wall_r_wolf, s_gen, s_inf);
}

void	draw_column_image(t_gener *s_gen, t_info *s_inf)
{
	if (s_inf->nb_texture_r == 1)
		put_image_wall(s_inf->image_m13, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 2)
		put_image_wall(s_inf->image_m07, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 3)
		put_image_wall(s_inf->image_m25, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 4)
		put_image_wall(s_inf->image_m01, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 5)
		put_image_wall(s_inf->image_door_in, s_gen, s_inf);
	else if (s_inf->nb_texture_r == 7)
		put_image_wall_got(s_inf->image_gofr2, s_gen, s_inf);
	else
		draw_column_image2(s_gen, s_inf);
}

void	draw_color_texture(t_gener *s_gen, t_info *s_inf)
{
	if (s_inf->color1_texture2 == 1)
		draw_column_color(s_gen, s_inf);
	else
	{
		draw_skybox(s_gen, s_inf);
		draw_column_image(s_gen, s_inf);
	}
}

void	draw_column(t_gener *s_gen, t_info *s_inf)
{
	int		height_column;
	double	right_d;

	height_column = 0;
	if (s_inf->dist_trass_y > s_inf->dist_trass_x)
	{
		right_d = s_inf->dist_trass_x *
		cos((s_inf->pov - s_inf->angle) * M_PI / 180);
		s_inf->nb_texture_r = s_inf->nb_texture_x;
		s_inf->wall_pos = s_inf->y_pos_rx;
		color_chooser(s_inf);
	}
	else
	{
		right_d = s_inf->dist_trass_y *
		cos((s_inf->pov - s_inf->angle) * M_PI / 180);
		s_inf->nb_texture_r = s_inf->nb_texture_y;
		s_inf->wall_pos = s_inf->x_pos_ry;
		color_chooser(s_inf);
	}
	height_column = s_inf->cube / right_d * s_inf->param_line;
	s_inf->height_point = s_gen->s_h / 2 - height_column / 2;
	s_inf->lower_point = s_gen->s_h / 2 + height_column / 2;
	draw_color_texture(s_gen, s_inf);
}
