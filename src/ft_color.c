/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:01:27 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:01:29 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_params *data, const char *find, const char *replace)
{
	const char	*ptr;
	size_t		len;

	ptr = &data->format[data->counter];
	len = ft_strlen(find);
	if (ft_memcmp(ptr, find, len) == 0)
	{
		ft_putstr_out(data, replace);
		data->counter += len;
		return (1);
	}
	return (0);
}

void				ft_color(t_params *data)
{
	if (check(data, "{red}", "\033[0;31m") ||
		check(data, "{green}", "\033[0;32m") ||
		check(data, "{brown}", "\033[0;33m") ||
		check(data, "{yellow}", "\033[1;33m") ||
		check(data, "{blue}", "\033[0;34m") ||
		check(data, "{purple}", "\033[0;35m") ||
		check(data, "{cyan}", "\033[0;36m") ||
		check(data, "{eoc}", "\033[0m"))
		;
	else
	{
		ft_putchar_total(data, data->format[data->counter]);
		data->counter++;
	}
}
