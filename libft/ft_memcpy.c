/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:54:14 by abao              #+#    #+#             */
/*   Updated: 2018/07/15 14:51:13 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int		x;
	char	*change;
	char	*source;

	change = (char *)str1;
	source = (char *)str2;
	x = 0;
	while (x < (int)n)
	{
		change[x] = source[x];
		x++;
	}
	return (change);
}
