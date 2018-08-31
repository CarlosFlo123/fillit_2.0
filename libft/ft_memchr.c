/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:53:08 by abao              #+#    #+#             */
/*   Updated: 2018/07/21 17:05:42 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function locates int c (converted to unsigned char) within s.
** It searches for the first occurence within n bytes.
** Param: string to search, char to find, bytes to search.
** Return: pointer to the location of the char, or NULL.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	str = (unsigned char*)s;
	while (n--)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
