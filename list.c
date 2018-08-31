/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflores- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 19:23:35 by cflores-          #+#    #+#             */
/*   Updated: 2018/08/30 19:23:56 by cflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*ft_list_new(void const *content, size_t content_size)
{
	t_list *list;

	if (NULL == (list = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (NULL == (list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

void		ft_list_add(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void		ft_list_rev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int			list_count(t_list *lst)
{
	int	i;

	i = 0;
	while (!lst)
	{
		lst = lst->next;
		i++;
	}
	return (1);
}
