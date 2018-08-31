/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:26:02 by abao              #+#    #+#             */
/*   Updated: 2018/07/15 14:39:51 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str1, int n, size_t len)
{
	char	*string;
	int		x;

	string = (char *)str1;
	x = 0;
	while (x < (int)len)
	{
		string[x] = n;
		x++;
	}
	return (string);
}
