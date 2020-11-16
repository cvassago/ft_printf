/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:45:14 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/16 15:37:27 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	k;
	size_t	i;

	i = 0;
	k = ft_strlen(dst);
	res = ft_strlen(src);
	if (size <= k)
		res = res + size;
	else
		res = res + k;
	while (src[i] && k + 1 < size)
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	dst[k] = '\0';
	return (res);
}
