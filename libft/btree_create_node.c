/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:13:04 by abao              #+#    #+#             */
/*   Updated: 2018/07/18 14:13:19 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree*)malloc(sizeof(t_btree));
	tree->item = item;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}
