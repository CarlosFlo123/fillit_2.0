/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:48:54 by abao              #+#    #+#             */
/*   Updated: 2018/07/16 16:45:02 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *str1, const char *find, size_t len)
{
	size_t	len2;

	if (*find == '\0')
		return ((char *)str1);
	len2 = ft_strlen(find);
	while (*str1 != '\0' && len-- >= len2)
	{
		if (*str1 == *find && ft_memcmp(str1, find, len2) == 0)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
