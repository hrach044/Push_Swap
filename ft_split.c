/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnatsak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:04:55 by hmnatsak          #+#    #+#             */
/*   Updated: 2026/03/28 16:34:26 by hmnatsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(const char *s, char c)
{
	int	words;
	int	t;

	words = 0;
	t = 0;
	while (*s)
	{
		if (*s != c && t == 0)
		{
			words++;
			t = 1;
		}
		else if (*s == c)
		{
			t = 0;
		}
		s++;
	}
	return (words);
}

char	**free_all(char **res, int words)
{
	while (words > 0)
	{
		words--;
		free(res[words]);
	}
	free(res);
	return (NULL);
}

int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*word_dup(char const *s, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			res[i] = word_dup(s, len);
			if (!res[i++])
				return (free_all(res, i - 1));
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}
