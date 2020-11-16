/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:16:52 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 15:13:44 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	clean(t_params *data)
{
	data->precision = -5;
	data->width = 0;
	data->minus_sign = 0;
	data->plus_sign = 0;
	data->space = 0;
	data->zero = 0;
	data->hash = 0;
	data->size = 0;
	data->type = '\0';
	data->negative = 0;
}

void				ft_parse_format(t_params *data)
{
	int	save;

	save = data->counter;
	data->counter++;
	clean(data);
	if (ft_parse_flags(data) &&
		ft_parse_width(data) &&
		ft_parse_precision(data) &&
		ft_parse_length(data) &&
		ft_parse_type(data) &&
		ft_parse_print(data))
		;
	else
	{
		data->counter = save;
		ft_putchar_total(data, data->format[data->counter]);
		data->counter++;
	}
}
