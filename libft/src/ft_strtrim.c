/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:45:40 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/16 19:09:50 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		k;
	char		*cop;
	size_t		n;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	if ((k = ft_strlen(s)) == (size_t)(-1))
		return (NULL);
	while (s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t')
		k--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (k <= 0 && i == ft_strlen(s))
		i = 0;
	cop = (char *)malloc(sizeof(char) * (k - i + 1));
	if (cop == NULL)
		return (NULL);
	while (i < k)
		cop[n++] = s[i++];
	cop[n] = '\0';
	return (cop);
}
