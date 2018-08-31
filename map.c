/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 14:48:40 by cflores-          #+#    #+#             */
/*   Updated: 2018/08/30 19:30:53 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->content[i]);
		write(1, "\n", 1);
		++i;
	}
}

/*
** Create the map with the given size (size = number of char).
*/

t_map		*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	if (NULL == (map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (NULL == (map->content = (char**)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		if (NULL == (map->content[i] = ft_strnew(size)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			map->content[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
** Free the allocated memory for the map struct.
*/

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		free(map->content[i]);
		i++;
	}
	free(map->content);
	free(map);
}

/*
** Place a tetromino on the map with the given coords.
*/

int			place_tetro(t_map *map, t_tetro *tetro, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetro->width)
	{
		j = 0;
		while (j < tetro->height)
		{
			if (tetro->pos[j][i] == '#' && map->content[y + j][x + i] != '.')
				return (0);
			++j;
		}
		++i;
	}
	setchar_tetro(map, tetro, create_point(x, y), tetro->letter);
	return (1);
}

/*
** Replace the char '#' by the corresponding tetromino char.
*/

void		setchar_tetro(t_map *map, t_tetro *tetro, t_point *point, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetro->width)
	{
		j = 0;
		while (j < tetro->height)
		{
			if (tetro->pos[j][i] == '#')
				map->content[point->y + j][point->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void**)&point);
}
