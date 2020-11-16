/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:31:42 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/13 09:52:54 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*n_dest;
	unsigned char	*n_src;
	size_t			i;

	i = 0;
	n_dest = (unsigned char *)dest;
	n_src = (unsigned char *)src;
	while (i < n)
	{
		if (n_src[i] != (unsigned char)c)
			n_dest[i] = n_src[i];
		else
		{
			n_dest[i] = n_src[i];
			return ((unsigned char *)(dest + i + 1));
		}
		i++;
	}
	return (NULL);
}
