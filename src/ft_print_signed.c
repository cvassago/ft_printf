/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:02:52 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:02:54 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline long long		get_value(t_params *data)
{
	long long	result;

	if (data->size == LENGTH_LL)
		result = (long long)va_arg(data->args, long long);
	else if (data->size == LENGTH_L)
		result = (long long)va_arg(data->args, long);
	else if (data->size == LENGTH_HH)
		result = (long long)(char)va_arg(data->args, int);
	else if (data->size == LENGTH_H)
		result = (long long)(short)va_arg(data->args, int);
	else
		result = (long long)va_arg(data->args, int);
	return (result);
}

static inline char			*recursive(char *ptr, unsigned long long value)
{
	if (value / 10 > 0)
		ptr = recursive(ptr, value / 10);
	*ptr = '0' + (value % 10);
	*(++ptr) = '\0';
	return (ptr);
}

static inline void			output(t_params *data, char sign)
{
	int		length;

	length = (int)ft_strlen(data->tmp);
	if (data->minus_sign)
		data->zero = 0;
	if (sign)
		data->width -= 1;
	if (data->precision < 0 && data->zero)
		data->precision = data->width;
	data->precision -= length;
	data->width -= length;
	if (data->precision > 0)
		data->width -= data->precision;
	if (!data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
	if (sign)
		ft_putchar_total(data, sign);
	ft_putchar_repeat(data, '0', data->precision);
	ft_putstr_out(data, data->tmp);
	if (data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
}

void						ft_print_signed(t_params *data)
{
	long long	value;
	char		sign;

	value = get_value(data);
	*(data->tmp) = '\0';
	if (!(data->precision == 0 && value == 0))
		recursive(data->tmp, (unsigned long long)(value < 0 ? -value : value));
	sign = '\0';
	if (data->space)
		sign = ' ';
	if (data->plus_sign)
		sign = '+';
	if (value < 0)
		sign = '-';
	output(data, sign);
}
