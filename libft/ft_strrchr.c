/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:22:48 by abao              #+#    #+#             */
/*   Updated: 2018/07/16 15:44:33 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		x;
	char	*new;

	x = 0;
	new = (char *)str;
	while (new[x] != '\0')
		x++;
	while (x >= 0)
	{
		if (new[x] == c)
			return (&new[x]);
		x--;
	}
	return (NULL);
}
