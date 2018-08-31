/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:54:20 by cflores-          #+#    #+#             */
/*   Updated: 2018/08/30 19:54:34 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Create an element of type t_tetro and assign value to attributes.
*/

t_tetro		*create_tetro(char **pos, int height, int width, char letter)
{
	t_tetro *tetros;

	if ((tetros = ft_memalloc(sizeof(t_tetro))) == NULL)
		return (NULL);
	tetros->pos = pos;
	tetros->height = height;
	tetros->width = width;
	tetros->letter = letter;
	return (tetros);
}

/*
** Create an element of type t_point and assign value to attributes.
*/

t_point		*create_point(int x, int y)
{
	t_point *point;

	if ((point = ft_memalloc(sizeof(t_point))) == NULL)
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

/*
** Store the min (x, y) and max (y, x) relative to the char '#' into a point
** struct.
*/

void		get_min_and_max(char *tetro, t_point *min, t_point *max)
{
	int	i;

	i = 0;
	while (i < 19)
	{
		if (tetro[i] == '#')
		{
			if (min->x > i % 5)
				min->x = i % 5;
			if (min->y > i / 5)
				min->y = i / 5;
			if (max->x < i % 5)
				max->x = i % 5;
			if (max->y < i / 5)
				max->y = i / 5;
		}
		i++;
	}
}

/*
** Create a struct tetromino (t_tetro) with the char given in parameter.
*/

t_tetro		*get_block(char *tetro, char c)
{
	t_point	*min;
	t_point	*max;
	char	**pos;
	int		i;
	t_tetro	*tetro_content;

	i = 0;
	min = create_point(3, 3);
	max = create_point(0, 0);
	get_min_and_max(tetro, min, max);
	pos = ft_memalloc(sizeof(char*) * (max->y - min->y) + 1);
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew((max->x - min->x) + 1);
		ft_memcpy(pos[i], &tetro[min->x + (i + min->y) * 5],
					(max->x - min->x) + 1);
		i++;
	}
	tetro_content = create_tetro(pos, (max->y - min->y) + 1,
									(max->x - min->x + 1), c);
	ft_memdel((void**)&min);
	ft_memdel((void**)&max);
	return (tetro_content);
}

/*
** Free all the tetrominos and their contents
*/

t_list		*free_all_tetro(t_list *lst_tetro)
{
	t_tetro		*tetro;
	t_list		*next;
	int			i;

	i = 0;
	while (lst_tetro)
	{
		tetro = (t_tetro*)lst_tetro->content;
		next = lst_tetro->next;
		while (i < tetro->height)
		{
			ft_memdel((void**)(&(tetro->pos[i])));
			i++;
		}
		ft_memdel((void**)&lst_tetro);
		lst_tetro = next;
	}
	return (NULL);
}
