/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:31:35 by abao              #+#    #+#             */
/*   Updated: 2018/08/30 19:36:36 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_map	*map;
	char	*tetris;
	t_list	*tetro_list;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if ((tetris = read_file(open(av[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!is_filevalid(tetris))
	{
		ft_putstr("error\n");
		return (0);
	}
	tetro_list = get_tetro_list(tetris);
	map = solve(tetro_list);
	print_map(map);
	free_map(map);
	free_all_tetro(tetro_list);
	return (1);
}
