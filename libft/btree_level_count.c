/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:15:46 by abao              #+#    #+#             */
/*   Updated: 2018/07/18 14:16:01 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_level_count(t_btree *root)
{
	t_btree	*tree;
	int		countl;
	int		countr;

	tree = root;
	countl = 0;
	countr = 0;
	while (tree)
	{
		countl = btree_level_count(tree->left) + 1;
		countr = btree_level_count(tree->right) + 1;
	}
	if (countl >= countr)
		return (countl);
	return (countr);
}
