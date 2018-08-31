/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 13:39:39 by abao              #+#    #+#             */
/*   Updated: 2018/07/22 15:14:52 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function deletes the memory of the link using the function given.
** the memory is then freed and the pointer is set to NULL.
** Param: Link to be deleted, the function to use to delete.
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
