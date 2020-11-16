/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:21:26 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/13 09:44:03 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *n_str, const void *str, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	if (n == 0 || n_str == str)
		return (n_str);
	src = (unsigned char *)str;
	dest = (unsigned char *)n_str;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (n_str);
}
