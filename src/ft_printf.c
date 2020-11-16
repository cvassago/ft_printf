/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:16:03 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 13:29:33 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_params data;

	ft_bzero(&data, sizeof(t_params));
	if (format)
	{
		if (format[0] == '%' && format[1] == '\0')
			return (0);
		data.fd = 1;
		va_start(data.args, format);
		data.format = format;
		ft_parse_while(&data);
		va_end(data.args);
	}
	else
		return (-1);
	return (data.total);
}
