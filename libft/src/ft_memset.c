/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:16:00 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/11 18:09:51 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*n_str;
	size_t			i;

	i = 0;
	n_str = (unsigned char *)str;
	while (i < n)
	{
		n_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
