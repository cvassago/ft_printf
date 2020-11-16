/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:24:11 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/12 17:21:32 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	k = ft_strlen(dest);
	while (app[i] != '\0' && i < n)
	{
		dest[k] = app[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
