/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:40:12 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/15 17:06:45 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <SDL.h>
# include <SDL_image.h>
# include "libft.h"
# include <math.h>

typedef struct		s_gener
{
	const Uint8		*keystate;
	SDL_Event		*event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*pixels;
	int				**map;
	int				**map_42;
	int				**big_map;
	int				**mini_map;
	int				line;
	int				s_h;
	int				s_w;
	int				map_width;
	int				map_height;
	int				mini_map_w;
	int				mini_map_h;
	int				big_map_w;
	int				big_map_h;
	int				map_42_w;
	int				map_42_h;
	int				quit;
	int				map_choose;
}					t_gener;

typedef struct		s_game_info
{
	double			pos_x;
	double			pos_y;
	double			pov;
	double			fov;
	double			pov_speed;
	double			pos_speed;
	double			angle;
	double			angle_r;
	double			y_pos_rx;
	double			x_pos_rx;
	double			y_pos_ry;
	double			x_pos_ry;
	double			x_pos_r_floor;
	double			y_pos_r_floor;
	int				real_y_pos_r;
	int				real_x_pos_r;
	int				wall_pos;
	double			y_dist;
	double			x_dist;
	double			dist_trass_x;
	double			dist_trass_y;
	double			param_line;
	int				nb_texture_y;
	int				nb_texture_x;
	int				nb_texture_r;
	int				nb_column;
	int				cube;
	int				height_point;
	int				lower_point;
	Uint32			color;
	int				color_bool;
	int				color1_texture2;
	SDL_Texture		*image_m25;
	SDL_Texture		*image_m13;
	SDL_Texture		*image_m01;
	SDL_Texture		*image_m07;
	SDL_Texture		*image_gofr1;
	SDL_Texture		*image_gofr2;
	SDL_Texture		*image_door_in;
	SDL_Texture		*skybox;
	SDL_Texture		*image_wall_wolf;
	SDL_Texture		*image_door_wolf;
	SDL_Texture		*image_wall_o_wolf;
	SDL_Texture		*image_wall_g_wolf;
	SDL_Texture		*image_door_wall_wolf;
	SDL_Texture		*image_wall_gray_wolf;
	SDL_Texture		*image_wall_r_wolf;
}					t_info;

typedef struct		s_map_creat
{
	char			*buf;
	char			*line;
	int				fd;
	int				i;
	int				k;
	int				x;
	int				y;
}					t_creat;

void				struct_init(t_gener *s);
void				dec_info(t_info *s);
void				ft_count_n(char *file, t_gener *str);
void				ft_error(char *file);
int					ft_words(char *str, char c);
int					sdl_start(t_gener *s_gen);
void				ray_cast_y(t_gener *s_gen, t_info *s_inf);
void				ray_cast_x(t_gener *s_gen, t_info *s_inf);
void				trass_y(t_gener *s_gen, t_info *s_inf);
void				trass_x(t_gener *s_gen, t_info *s_inf);
void				ray_casting(t_gener *s_gen, t_info *s_inf);
void				draw_column(t_gener *s_gen, t_info *s_inf);
void				sdl_all(t_gener *s_gen, t_info *s_inf);
void				map_int_malloc(t_gener *s_gen);
void				map_create(char *file, t_gener *s);
void				put_image_wall(SDL_Texture *image,
		t_gener *s_gen, t_info *s_inf);
void				put_image_wall_got(SDL_Texture *image,
		t_gener *s_gen, t_info *s_inf);
void				put_image_wall_64(SDL_Texture *image,
		t_gener *s_gen, t_info *s_inf);
void				color_chooser(t_info *s_inf);
void				draw_column_color(t_gener *s_gen, t_info *s_inf);
void				image_load(t_gener *s_gen, t_info *s_inf);
void				draw_column_image(t_gener *s_gen, t_info *s_inf);
void				draw_skybox(t_gener *s_gen, t_info *s_inf);
void				draw_mini_map(t_gener *s_gen, t_info *s_inf);
void				draw_back_mini(t_gener *s_gen, t_info *s_inf);
void				draw_wall_cord(t_gener *s_gen, t_info *s_inf, int y, int x);
void				draw_mini_wall(t_gener *s_gen, t_info *s_inf);
void				draw_mini_position(t_gener *s_gen, t_info *s_inf);
void				renderer_mini_map(t_gener *s_gen, t_info *s_inf);
void				key_up(t_gener *s_gen, t_info *s_inf);
void				key_down(t_gener *s_gen, t_info *s_inf);
void				ft_floor_color(t_gener *s_gen);
void				ft_sky_color(t_gener *s_gen);
void				maps_creation(t_gener *s_gen);

#endif
