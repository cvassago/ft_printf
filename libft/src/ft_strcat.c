/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:57:02 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/12 17:19:59 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *app)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(dest);
	while (app[i] != '\0')
	{
		dest[k] = app[i];
		k++;
		i++;
	}
	dest[k] = '\0';
	return (dest);
}
