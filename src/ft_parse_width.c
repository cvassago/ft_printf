/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:18:23 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/27 21:22:19 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_width(t_params *data)
{
	int		save;
	int		temp;

	data->width = -1;
	if (data->format[data->counter] == '*')
	{
		data->counter++;
		data->width = (int)va_arg(data->args, int);
		if (data->width < 0)
		{
			data->minus_sign = 1;
			data->width *= -1;
		}
	}
	save = data->counter;
	temp = ft_parse_number(data);
	if (save != data->counter)
		data->width = temp;
	return (1);
}
