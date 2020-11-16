/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:02:17 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:02:19 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_params *data)
{
	char	*str;
	int		len;

	str = (char *)va_arg(data->args, char *);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (data->precision < 0 || data->precision > len)
		data->precision = len;
	data->width -= data->precision;
	if (data->zero && data->minus_sign)
		data->zero = 0;
	if (data->zero)
		ft_putchar_repeat(data, '0', data->width);
	if (!data->minus_sign && !data->zero)
		ft_putchar_repeat(data, ' ', data->width);
	ft_putstr_total(data, str, data->precision);
	if (data->minus_sign)
		ft_putchar_repeat(data, ' ', data->width);
}
