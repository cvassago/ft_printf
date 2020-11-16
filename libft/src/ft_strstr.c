/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:56:51 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/16 17:22:12 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str_in, const char *str_from)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!ft_strlen(str_from))
		return ((char *)str_in);
	while (str_in[i] != '\0')
	{
		while (str_in[k + i] == str_from[k] && str_from[k] != '\0')
			k++;
		i++;
		if (k != ft_strlen(str_from))
			k = 0;
		else
			return ((char *)(str_in + i - 1));
	}
	return (NULL);
}
