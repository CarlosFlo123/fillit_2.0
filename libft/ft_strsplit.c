/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 11:06:19 by abao              #+#    #+#             */
/*   Updated: 2018/07/22 19:11:04 by abao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function takes a given string with words seperated by a given delimiter.
** The string is seperated into an array of arrays, each word as its own node.
** This is done by creating the char **, using malloc to get the size,
** then trimming the delim, finding the chars,
** and putting it in a string until the next delim. Where tf is the segfault?
** Param: the string to be split, the delimiter.
** Return: The array of strings.
*/

#include "libft.h"
#include <stdlib.h>

static int	count(char const *s, int start, char c)
{
	int		length;

	length = 0;
	while (s[start] && s[start] != c)
	{
		length++;
		start++;
	}
	return (length);
}

static int	word_count(char const *s, int place, char c)
{
	int		words;

	words = 0;
	while (s[place] == c)
		place++;
	while (s[place])
	{
		if (s[place] == c || s[place] == '\0')
		{
			words++;
			place++;
			while (s[place] == c)
				place++;
		}
		else
			place++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**final;
	int		words;
	int		len;

	words = 0;
	len = 0;
	final = (char **)malloc(sizeof(char **) * (word_count(s, len, c) + 2));
	if (!final)
		return (NULL);
	while (s[len] == c)
		len++;
	while (s[len])
	{
		while (s[len] == c)
			len++;
		if (s[len] == '\0')
			break ;
		final[words] = ft_strsub(s, len, count(s, len, c));
		words++;
		len = len + count(s, len, c);
	}
	if (words > 0)
		final[words] = NULL;
	return (final);
}
