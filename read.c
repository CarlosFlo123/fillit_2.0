/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:50:46 by cflores-          #+#    #+#             */
/*   Updated: 2018/08/30 19:50:24 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if the tetro is valid by checking if each '#' has an other adjacent
** '#' and if the total number of connections are equals to 8 or 6.
*/

int		is_validpiece(char *tetros)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i <= 19)
	{
		if (tetros[i] == '#')
		{
			if (i - 1 >= 0 && tetros[i - 1] == '#')
				count++;
			if (i + 1 <= 19 && tetros[i + 1] == '#')
				count++;
			if (i + 5 <= 19 && tetros[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && tetros[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 8)
		return (1);
	if (count == 6)
		return (1);
	return (0);
}

/*
** Check if the tetro block is valid :
** Contains only '.' and '#' (max 4).
** Tetro is 4x4
** Line separated with \n.
** Block is separated with \n with the next (if there is).
*/

int		is_blockvalid(char *tetros)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	while ((tetros[i] == '.' || tetros[i] == '#' || tetros[i] == '\n') &&
			hash < 5 && tetros[i])
	{
		if (i == 20)
			break ;
		if ((i + 1 % 5 == 0) && tetros[i] != '\n' && i != 0)
			return (0);
		if (tetros[i] == '#')
			hash++;
		i++;
	}
	if (hash == 4 && is_validpiece(tetros))
	{
		if (((tetros[i] == '\n' && tetros[i - 1] == '\n') || tetros[i] == '\0')
				&& hash == 4 && i == 20)
			return (1);
	}
	return (0);
}

/*
** Check if file is valid :
** Loop on file content, check if each block is valid and add blocks to list.
*/

int		is_filevalid(char *tetros)
{
	int		i;

	i = 0;
	if (tetros == NULL || tetros[0] == '\0')
		return (0);
	while (tetros[i])
	{
		if (i >= 546)
			return (0);
		if (is_blockvalid(&tetros[i]) == 0)
			return (0);
		i += 19;
		if (tetros[i + 1] && tetros[i + 2] == '\0')
			return (0);
		if (tetros[i + 1] == '\n')
			i += 2;
		else
			break ;
	}
	return (1);
}

/*
** Add each tetromino to the chained list and reverse the final list to get
** the first link.
*/

t_list	*get_tetro_list(char *tetros)
{
	int		i;
	char	c;
	t_list	*tetro_list;
	t_tetro *tetro;

	tetro_list = NULL;
	tetro = NULL;
	c = 'A';
	i = 0;
	while (tetros[i])
	{
		tetro = get_block(&tetros[i], c);
		ft_list_add(&tetro_list, ft_list_new(tetro, sizeof(t_tetro)));
		i += 19;
		if (tetros[i + 1] == '\n')
			i += 2;
		else
			break ;
		c++;
	}
	ft_list_rev(&tetro_list);
	return (tetro_list);
}

/*
** Read the file with the given file descriptor and return the content of it.
*/

char	*read_file(int fd)
{
	char	*tetros;
	char	*buffer;
	int		fr;

	buffer = ft_strnew(20);
	if ((fd < 0 || read(fd, buffer, 0) < 0))
		return (NULL);
	tetros = (char*)ft_memalloc(sizeof(char));
	while ((fr = read(fd, buffer, 20)))
	{
		buffer[fr] = '\0';
		tetros = ft_strjoin(tetros, buffer);
		if (ft_strlen(tetros) > 570)
			return (NULL);
	}
	ft_memdel((void**)&buffer);
	tetros = ft_strjoin(tetros, "\0");
	return (tetros);
}
