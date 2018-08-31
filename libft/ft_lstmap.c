/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:32:52 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 14:29:40 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function iterates through a list and applies a function to each link.
** Uses malloc to create a new link. Ends when the content given is null.
** Param: list with pointer to first item, and function.
** Return: new list.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
