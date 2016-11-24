/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:57:40 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 20:57:43 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map_42_creat(t_gener *s_gen)
{
	s_gen->map_width = 0;
	s_gen->map_height = 0;
	ft_count_n("./maps/map_42", s_gen);
	map_int_malloc(s_gen);
	map_create("./maps/map_42", s_gen);
	s_gen->map_42 = s_gen->map;
	s_gen->map_42_w = s_gen->map_width;
	s_gen->map_42_h = s_gen->map_height;
}

void	big_map_creat(t_gener *s_gen)
{
	s_gen->map_width = 0;
	s_gen->map_height = 0;
	ft_count_n("./maps/bigmap", s_gen);
	map_int_malloc(s_gen);
	map_create("./maps/bigmap", s_gen);
	s_gen->big_map = s_gen->map;
	s_gen->big_map_w = s_gen->map_width;
	s_gen->big_map_h = s_gen->map_height;
}

void	mini_map_creat(t_gener *s_gen)
{
	s_gen->map_width = 0;
	s_gen->map_height = 0;
	ft_count_n("./maps/minimap", s_gen);
	map_int_malloc(s_gen);
	map_create("./maps/minimap", s_gen);
	s_gen->mini_map = s_gen->map;
	s_gen->mini_map_w = s_gen->map_width;
	s_gen->mini_map_h = s_gen->map_height;
}

void	maps_creation(t_gener *s_gen)
{
	map_42_creat(s_gen);
	big_map_creat(s_gen);
	mini_map_creat(s_gen);
}
