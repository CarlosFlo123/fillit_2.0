/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:04:20 by abao              #+#    #+#             */
/*   Updated: 2018/07/21 19:36:19 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc(size + 1);
	if (string == NULL)
		return (NULL);
	ft_memset(string, (int)'\0', size + 1);
	return (string);
}
