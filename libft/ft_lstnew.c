/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:17:16 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 14:39:17 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Using malloc, allocates a fresh link of a list.
** Node is given content of content size unless null.
** Use copy to give node content.
** Param: Content to be given to node, size of content.
** Return: new link.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (!content)
	{
		node->content = (void *)content;
		node->content_size = 0;
	}
	else
	{
		node->content = (void *)malloc(content_size);
		if (!node->content)
			return (NULL);
		ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}
