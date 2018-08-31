/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:15:03 by abao              #+#    #+#             */
/*   Updated: 2018/07/20 11:17:27 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_infix(t_btree *root, void (*applyf) (void *))
{
	t_btree	*tree;

	tree = root;
	if (!root || root->item == 0)
		return ;
	btree_apply_prefix(tree->left, applyf);
	(*applyf)(tree->item);
	btree_apply_prefix(tree->right, applyf);
}
