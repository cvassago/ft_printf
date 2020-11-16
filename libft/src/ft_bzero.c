/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:12:30 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/11 18:10:20 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*n_str;
	size_t			i;

	i = 0;
	n_str = (unsigned char *)str;
	while (i < n)
	{
		n_str[i] = '\0';
		i++;
	}
}
