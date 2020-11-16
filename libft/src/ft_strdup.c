/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:50:51 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/11 18:17:36 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*n_str;

	if (str == NULL)
		return (NULL);
	n_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (n_str == NULL)
		return (NULL);
	else
		return (ft_strcpy(n_str, str));
}
