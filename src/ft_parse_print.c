/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:17:34 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 15:13:52 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_params *data, char type, void (*func)())
{
	if (data->type == type)
	{
		(*func)(data);
		return (1);
	}
	return (0);
}

int					ft_parse_print(t_params *data)
{
	if (check(data, 'c', &ft_print_char) ||
		check(data, 's', &ft_print_string) ||
		check(data, 'p', &ft_print_hex) ||
		check(data, 'd', &ft_print_signed) ||
		check(data, 'i', &ft_print_signed) ||
		check(data, 'o', &ft_print_octal) ||
		check(data, 'u', &ft_print_unsigned) ||
		check(data, 'x', &ft_print_hex) ||
		check(data, 'X', &ft_print_hex) ||
		check(data, 'f', &ft_print_double) ||
		check(data, '%', &ft_print_esc))
		return (1);
	return (0);
}
