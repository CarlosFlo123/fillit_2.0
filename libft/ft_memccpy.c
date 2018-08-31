/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:16:57 by abao              #+#    #+#             */
/*   Updated: 2018/07/22 15:12:47 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*desti;

	i = 0;
	source = (unsigned char *)str2;
	desti = (unsigned char *)str1;
	while (i < n)
	{
		desti[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (desti + i + 1);
		i++;
	}
	return (NULL);
}
