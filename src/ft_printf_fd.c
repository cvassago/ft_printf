/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:04:34 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:04:36 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_fd(int fd, char *format, ...)
{
	t_params data;

	ft_bzero(&data, sizeof(t_params));
	if (format)
	{
		if (format[0] == '%' && format[1] == '\0')
			return (0);
		data.fd = fd;
		va_start(data.args, format);
		data.format = format;
		ft_parse_while(&data);
		va_end(data.args);
	}
	else
		return (-1);
	return (data.total);
}
