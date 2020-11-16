/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_esc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:47:31 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 14:46:26 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_esc(t_params *data)
{
	if (data->zero && data->minus_sign)
		data->zero = 0;
	if (data->zero)
		ft_putchar_repeat(data, '0', data->width - 1);
	if (data->minus_sign == 1)
		ft_putchar_total(data, '%');
	if (!data->zero)
		ft_putchar_repeat(data, ' ', data->width - 1);
	if (data->minus_sign == 0)
		ft_putchar_total(data, '%');
}
