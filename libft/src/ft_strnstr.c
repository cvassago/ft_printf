/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:33:25 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/13 11:49:28 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str_in, const char *str_from, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if ((size_t)ft_strlen(str_from) == 0)
		return ((char *)str_in);
	if ((size_t)ft_strlen(str_from) > n && n == 0)
		return (NULL);
	while (str_in[i] != '\0' && i < n)
	{
		while (str_in[k + i] == str_from[k] && str_from[k] != '\0' && k + i < n)
			k++;
		i++;
		if (k != (size_t)ft_strlen(str_from))
			k = 0;
		else
			return ((char *)(str_in + i - 1));
	}
	return (NULL);
}
