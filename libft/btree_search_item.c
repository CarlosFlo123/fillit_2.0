/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:12:03 by abao              #+#    #+#             */
/*   Updated: 2018/07/21 13:48:59 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf) (void *, void *))
{
	t_btree	*tree;

	tree = root;
	if (!root)
		return (NULL);
	btree_search_item(tree->left, data_ref, cmpf);
	if ((*cmpf)(tree->item, data_ref) == 0)
		return (tree);
	btree_search_item(tree->right, data_ref, cmpf);
	return (tree);
}
