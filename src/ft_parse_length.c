/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:17:02 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/27 21:22:19 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_params *data, char *str, t_length value)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (data->format[data->counter + i] != str[i])
			return (0);
		i++;
	}
	data->size = value;
	data->counter += i;
	return (1);
}

int					ft_parse_length(t_params *data)
{
	if (check(data, "hh", LENGTH_HH) ||
		check(data, "ll", LENGTH_LL) ||
		check(data, "h", LENGTH_H) ||
		check(data, "l", LENGTH_L) ||
		check(data, "L", LENGTH_CAP_L))
		return (1);
	return (1);
}
