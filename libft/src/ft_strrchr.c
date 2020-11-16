/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:53:17 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/12 18:00:16 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)ch)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
