/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:21:22 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 14:45:09 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a memory area via void pointer.
** The allocated space is then initialized to 0.
** Pararm: size of allocated space.
** Return: new memory area.
*/

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*space;

	space = malloc(size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, size);
	return (space);
}
