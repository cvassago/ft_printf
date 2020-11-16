/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:16:43 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/27 21:22:19 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_params *data, char flag, int *is_flag)
{
	if (data->format[data->counter] == flag)
	{
		*is_flag = 1;
		data->counter++;
		return (1);
	}
	return (0);
}

int					ft_parse_flags(t_params *data)
{
	while (check(data, '#', &data->hash) ||
		check(data, '0', &data->zero) ||
		check(data, '-', &data->minus_sign) ||
		check(data, '+', &data->plus_sign) ||
		check(data, ' ', &data->space))
		;
	return (1);
}
