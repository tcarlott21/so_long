/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:18:01 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:18:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			cnt ++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (cnt);
}

static char	*ft_word_make(char *word, char const *s, int k, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		word[i] = s[k - word_len];
		i++;
		word_len--;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_split2(char **tab, char const *s, char c, int word_num)
{
	int	i;
	int	k;
	int	word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		tab[i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_word_make(tab[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**tab;

	if (!s)
		return (0);
	word_num = ft_word_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!tab)
		return (0);
	ft_split2(tab, s, c, word_num);
	return (tab);
}
