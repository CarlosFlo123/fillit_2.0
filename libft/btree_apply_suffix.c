/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:16:24 by abao              #+#    #+#             */
/*   Updated: 2018/07/21 13:47:04 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*applyf) (void *))
{
	t_btree	*tree;

	tree = root;
	if (!root || root->item == 0)
		return ;
	btree_apply_suffix(tree->left, applyf);
	btree_apply_suffix(tree->right, applyf);
	(*applyf)(tree->item);
}
