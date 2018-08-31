/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:50:44 by cflores-          #+#    #+#             */
/*   Updated: 2018/08/30 19:50:53 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		back_track(t_map *map, t_list *lst)
{
	int		i;
	int		j;
	t_tetro	*tetro;

	if (lst == NULL)
		return (1);
	j = 0;
	tetro = (t_tetro*)(lst->content);
	while (j < map->size - tetro->height + 1)
	{
		i = 0;
		while (i < map->size - tetro->width + 1)
		{
			if (place_tetro(map, tetro, i, j))
			{
				if (back_track(map, lst->next))
					return (1);
				else
					setchar_tetro(map, tetro, create_point(i, j), '.');
			}
			i++;
		}
		j++;
	}
	return (0);
}

t_map	*solve(t_list *lst)
{
	t_map	*map;
	int		size;

	size = 2;
	while (size * size < list_count(lst) * 4)
		size++;
	map = create_map(size);
	while (!back_track(map, lst))
	{
		size++;
		free_map(map);
		map = create_map(size);
	}
	return (map);
}
