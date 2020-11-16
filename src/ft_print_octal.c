/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:04:46 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:04:47 by cvassago         ###   ########.fr       */
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
	if (value / 8 > 0)
		ptr = recursive(ptr, value / 8);
	*ptr = '0' + (value % 8);
	*(++ptr) = '\0';
	return (ptr);
}

static inline void					output(t_params *data, char *string)
{
	if (!data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
	if (data->hash)
		ft_putchar_total(data, '0');
	ft_putchar_repeat(data, '0', data->precision);
	ft_putstr_out(data, string);
	if (data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
}

void								ft_print_octal(t_params *data)
{
	unsigned long long	value;
	int					length;

	value = get_value(data);
	*(data->tmp) = '\0';
	if (!(!data->hash && !data->precision && value == 0))
		recursive(data->tmp, value);
	length = (int)ft_strlen(data->tmp);
	if (value == 0)
		data->hash = 0;
	if (data->hash)
		length += 1;
	if (data->minus_sign)
		data->zero = 0;
	if (data->precision < 0 && data->zero)
		data->precision = data->width;
	data->precision -= length;
	data->width -= length;
	if (data->precision > 0)
		data->width -= data->precision;
	output(data, data->tmp);
}
