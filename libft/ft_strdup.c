/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:14:07 by abao              #+#    #+#             */
/*   Updated: 2018/07/22 15:12:24 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		count;

	new = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	count = 0;
	while (src[count] != '\0')
	{
		new[count] = src[count];
		count++;
	}
	new[count] = '\0';
	return (new);
}
