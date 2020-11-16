/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:05:31 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/31 14:48:11 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline double long			get_value(t_params *data)
{
	double long		result;

	if (data->size == LENGTH_CAP_L)
		result = (double long)va_arg(data->args, double long);
	else
		result = (double long)va_arg(data->args, double);
	return (result);
}

void								make(t_params *data,
	unsigned long long part1, unsigned long long part2)
{
	int		length;

	length = 0;
	while (part2)
	{
		data->tmp[length++] = '0' + (part2 % 10);
		part2 = part2 / 10;
	}
	while (length < data->precision)
		data->tmp[length++] = '0';
	if (length > 0)
		data->tmp[length++] = '.';
	if (part1 == 0)
		data->tmp[length++] = '0';
	while (part1)
	{
		data->tmp[length++] = '0' + (part1 % 10);
		part1 = part1 / 10;
	}
	data->tmp[length] = '\0';
}

static inline void					output(t_params *data, char sign)
{
	int		length;

	length = (int)ft_strlen(data->tmp);
	if (data->plus_sign)
		sign = '+';
	if (data->negative)
		sign = '-';
	data->width -= (length + (sign ? 1 : 0));
	data->width -= (data->hash && !data->precision ? 1 : 0);
	if (data->zero && data->minus_sign)
		data->zero = 0;
	if (!data->minus_sign && !data->zero)
		ft_putchar_repeat(data, ' ', data->width);
	if (sign)
		ft_putchar_total(data, sign);
	if (!data->minus_sign && data->zero)
		ft_putchar_repeat(data, '0', data->width);
	while (length-- > 0)
		ft_putchar_total(data, data->tmp[length]);
	if (data->hash && data->precision == 0)
		ft_putchar_total(data, '.');
	if (data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
}

static inline unsigned long long	power10(int n)
{
	unsigned long long	result;

	result = 1;
	while (n-- > 0)
		result *= 10;
	return (result);
}

void								ft_print_double(t_params *data)
{
	double long			value;
	unsigned long long	part1;
	unsigned long long	pow10;
	char				sign;

	value = get_value(data);
	if (ft_inf_nan(data, value))
		return ;
	sign = '\0';
	if (data->space)
		sign = ' ';
	if (value < 0 || ft_sign(value))
		data->negative = 1;
	if (value < 0)
		value = -value;
	if (data->precision < 0)
		data->precision = 6;
	pow10 = power10(data->precision + 1);
	part1 = (unsigned long long)value;
	value = (value - (double long)part1) * (double long)pow10;
	value = ((unsigned long long)value % 10 > 4) ? value / 10 + 1 : value / 10;
	part1 += (unsigned long long)value / (pow10 / 10);
	make(data, part1, (unsigned long long)value % (pow10 / 10));
	output(data, sign);
}
