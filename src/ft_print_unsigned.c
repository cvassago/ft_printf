/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:02:39 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:02:43 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline unsigned long long	get_value(t_params *data)
{
	unsigned long long	result;

	if (data->size == LENGTH_LL)
		result = (unsigned long long)va_arg(data->args, unsigned long long);
	else if (data->size == LENGTH_L)
		result = (unsigned long long)va_arg(data->args, unsigned long);
	else if (data->size == LENGTH_HH)
		result = (unsigned long long)(unsigned char)\
			va_arg(data->args, unsigned int);
	else if (data->size == LENGTH_H)
		result = (unsigned long long)(unsigned short)\
			va_arg(data->args, unsigned int);
	else
		result = (unsigned long long)va_arg(data->args, unsigned int);
	return (result);
}

static inline char					*recursive(char *ptr,
									unsigned long long value)
{
	if (value / 10 > 0)
		ptr = recursive(ptr, value / 10);
	*ptr = '0' + (value % 10);
	*(++ptr) = '\0';
	return (ptr);
}

void								ft_print_unsigned(t_params *data)
{
	unsigned long long	value;
	int					length;

	value = get_value(data);
	*(data->tmp) = '\0';
	if (!(data->precision == 0 && value == 0))
		recursive(data->tmp, value);
	length = (int)ft_strlen(data->tmp);
	if (data->precision < 0 && data->zero)
		data->precision = data->width;
	data->precision -= length;
	data->width -= length;
	if (data->precision > 0)
		data->width -= data->precision;
	if (!data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
	ft_putchar_repeat(data, '0', data->precision);
	ft_putstr_out(data, data->tmp);
	if (data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
}
