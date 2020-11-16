/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:46:54 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/18 19:13:04 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	unsigned int	u_save;
	char			*str;
	int				i;

	i = 1;
	u_save = n < 0 ? -n : n;
	while (u_save /= 10)
		i++;
	n < 0 ? i++ : 0;
	u_save = n < 0 ? -n : n;
	if (!(str = (char *)malloc(i + 1)))
		return (0);
	str[0] = '0';
	str[i] = 0;
	while (i)
	{
		str[i - 1] = u_save % 10 + '0';
		u_save /= 10;
		i--;
	}
	n < 0 ? (str[0] = '-') : 0;
	return (str);
}
