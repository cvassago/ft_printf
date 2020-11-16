/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_while.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:18:16 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:01:09 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_while(t_params *data)
{
	char	simb;

	while ((simb = data->format[data->counter]))
	{
		if (simb == '%')
			ft_parse_format(data);
		else if (simb == '{')
			ft_color(data);
		else
		{
			ft_putchar_total(data, data->format[data->counter]);
			data->counter++;
		}
	}
	ft_flush_out(data);
}
