/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:32:22 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/20 19:12:57 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_long(size_t res, int neg, char c)
{
	if ((res > 922337203685477580 || (res == 922337203685477580 && c > '8')) &&
			neg == -1)
		return (0);
	if ((res > 922337203685477580 || (res == 922337203685477580 && c > '7')) &&
			neg == 1)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_long(res, neg, str[i]) != 1)
			return (ft_long(res, neg, str[i]));
		res = res * 10 + (str[i++] - 48);
	}
	return ((int)(res * neg));
}
