/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:17:24 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 14:24:36 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_precision(t_params *data)
{
	if (data->format[data->counter] == '.')
	{
		data->counter++;
		if (data->format[data->counter] == '*')
		{
			data->counter++;
			data->precision = (int)va_arg(data->args, int);
		}
		else
		{
			data->precision = ft_parse_number(data);
		}
	}
	else
		data->precision = -5;
	return (1);
}
