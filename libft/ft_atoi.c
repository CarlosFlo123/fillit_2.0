/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:50:50 by abao              #+#    #+#             */
/*   Updated: 2018/07/22 15:16:12 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function converts an argument into an integer.
** Start by trimming white space.
** Then, *10, take the char and cast, - '0'
** Account for min and max. Somehow. IDK.
** Seriously, does no one else have this problem?
** Am I going crazy? How tf do I do this? Do I need to return 0?
** Param: string to convert.
** Return: converted int, or 0 if not an int.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	new;
	int	neg;

	c = 0;
	new = 0;
	neg = 1;
	while (str[c] == '\n' || str[c] == '\v' || str[c] == '\t' ||
			str[c] == '\f' || str[c] == '\r' || str[c] == ' ')
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			neg = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		new *= 10;
		new = new + ((int)str[c] - '0');
		c++;
	}
	new = new * neg;
	return (new);
}
