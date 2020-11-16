/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_inf_nan.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:38:49 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 19:56:40 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	min_inf(t_params *data, double long arg)
{
	if (arg < -LDBL_MAX)
	{
		if (data->precision < 0 || data->precision > 4)
			data->precision = 4;
		data->width -= data->precision;
		if (!data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		ft_putstr_total(data, "-inf", data->precision);
		if (data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		return (1);
	}
	return (0);
}

static inline int	max_inf(t_params *data, double long arg)
{
	int	count;

	count = 3 + (data->plus_sign ? 1 : 0);
	if (arg > LDBL_MAX)
	{
		if (data->precision < 0 || data->precision > count)
			data->precision = count;
		data->width -= data->precision;
		if (!data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		if (!data->plus_sign && data->space)
			ft_putchar_total(data, ' ');
		if (data->plus_sign)
			ft_putchar_total(data, '+');
		ft_putstr_total(data, "inf", data->precision);
		if (data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		return (1);
	}
	return (0);
}

static inline int	nan(t_params *data, double long arg)
{
	if (arg != arg)
	{
		if (data->precision < 0 || data->precision > 3)
			data->precision = 3;
		data->width -= data->precision;
		if (!data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		ft_putstr_total(data, "nan", data->precision);
		if (data->minus_sign)
			ft_putchar_repeat(data, ' ', data->width);
		return (1);
	}
	return (0);
}

int					ft_inf_nan(t_params *data, double long arg)
{
	if (nan(data, arg) ||
		max_inf(data, arg) ||
		min_inf(data, arg))
		return (1);
	return (0);
}
