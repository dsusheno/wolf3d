/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:57:01 by dsusheno          #+#    #+#             */
/*   Updated: 2016/09/14 20:57:04 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	map_int_malloc(t_gener *s_gen)
{
	int y;

	y = 0;
	s_gen->map = (int **)malloc(sizeof(int *) * (s_gen->map_height + 1));
	while (y < s_gen->map_height)
	{
		s_gen->map[y] = (int *)malloc(sizeof(int) * (s_gen->map_width + 1));
		ft_bzero(s_gen->map[y], s_gen->map_width + 1);
		y++;
	}
	s_gen->map[y] = NULL;
}

void	map_create_while(t_gener *s, t_creat *s_creat)
{
	while (s_creat->line[s_creat->i] != '\0')
	{
		if (s_creat->line[s_creat->i] == ' ')
		{
			while (s_creat->line[s_creat->i] == ' ')
				s_creat->i++;
			s->map[s_creat->y][s_creat->x] = ft_atoi(s_creat->buf);
			ft_bzero(s_creat->buf, 100);
			s_creat->k = 0;
			s_creat->x++;
		}
		s_creat->buf[s_creat->k] = s_creat->line[s_creat->i];
		s_creat->k++;
		s_creat->i++;
	}
	s->map[s_creat->y][s_creat->x] = ft_atoi(s_creat->buf);
	s_creat->y++;
	s_creat->i = 0;
	s_creat->x = 0;
	s_creat->k = 0;
	ft_bzero(s_creat->buf, 100);
	if (s_creat->line)
		free(s_creat->line);
}

void	map_create(char *file, t_gener *s)
{
	t_creat s_creat;

	s_creat.k = 0;
	s_creat.i = 0;
	s_creat.y = 0;
	s_creat.x = 0;
	s_creat.buf = ft_memalloc(100);
	s_creat.fd = open(file, O_RDONLY);
	if (s_creat.fd == -1)
		ft_error(file);
	while (get_next_line(s_creat.fd, &s_creat.line))
		map_create_while(s, &s_creat);
	if (s_creat.buf)
		free(s_creat.buf);
}

int		ft_words(char *str, char c)
{
	int				count_word;
	int				j;
	int				is_word;

	j = 0;
	count_word = 0;
	is_word = 1;
	while (str[j])
	{
		if (str[j] != c && is_word == 1)
		{
			is_word = 0;
			count_word++;
		}
		if (str[j] == c && is_word == 0)
			is_word = 1;
		j++;
	}
	return (count_word);
}

void	ft_count_n(char *file, t_gener *str)
{
	int		fd;
	char	*s;
	int		r;

	str->map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(file);
	while ((r = get_next_line(fd, &s)))
	{
		if (r == -1)
			ft_error(file);
		if (!(ft_isprint(s[0])))
		{
			ft_putstrn("fdf: Invalid File");
			exit(0);
		}
		if (str->map_width < ft_words(s, ' '))
			str->map_width = ft_words(s, ' ');
		if (s)
			free(s);
		str->map_height++;
	}
	close(fd);
}
