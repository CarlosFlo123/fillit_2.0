/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:38:43 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 13:31:14 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function creates a new node at the beginning of the list. No return.
** Param: the original list, content of the new node to be added
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*lsthead;

	lsthead = *alst;
	*alst = new;
	new->next = lsthead;
}
