/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:10:58 by abao              #+#    #+#             */
/*   Updated: 2018/07/16 15:07:59 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *source, size_t len)
{
	int	count;

	count = 0;
	while ((source[count] != '\0') && count < (int)len)
	{
		dest[count] = source[count];
		count++;
	}
	if (source[count] == '\0')
	{
		while (count < (int)len)
		{
			dest[count] = '\0';
			count++;
		}
	}
	return (dest);
}
