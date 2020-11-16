/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:20:40 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/24 18:58:22 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char		*ft_new_word(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	return (ft_strncpy(str, s, i));
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		k;
	char		**str;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[i] && k != ft_count_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (!(str[k] = ft_new_word((s + i), c)))
		{
			ft_clean(&str);
			return (NULL);
		}
		k++;
		while (s[i] != c && s[i])
			i++;
	}
	str[k] = 0;
	return (str);
}
