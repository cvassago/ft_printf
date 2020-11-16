/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:17:12 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/27 21:22:19 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_number(t_params *data)
{
	int		result;

	result = 0;
	while (ft_isdigit(data->format[data->counter]))
	{
		result *= 10;
		result += data->format[data->counter] - '0';
		data->counter++;
	}
	return (result);
}
