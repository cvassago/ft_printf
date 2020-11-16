/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:16:13 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 14:26:54 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_params *data)
{
	char	value;

	value = (char)va_arg(data->args, int);
	if (data->minus_sign)
		ft_putchar_total(data, value);
	ft_putchar_repeat(data, ' ', data->width - 1);
	if (!data->minus_sign)
		ft_putchar_total(data, value);
}
