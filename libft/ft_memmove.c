/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:04:22 by abao              #+#    #+#             */
/*   Updated: 2018/07/17 19:19:23 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *str1, const void *str2, size_t length)
{
	if (str2 <= str1)
		while (length--)
			((unsigned char *)str1)[length] = ((unsigned char *)str2)[length];
	else
		ft_memcpy(str1, str2, length);
	return ((void *)str1);
}
