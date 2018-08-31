/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:52:07 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 14:07:40 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates through given list with function.
** Param: list to have function applied to, function to apply
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
