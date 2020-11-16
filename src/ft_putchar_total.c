/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_total.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:17:49 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 15:13:27 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_total(t_params *data, char c)
{
	if (data->count_buff == FT_BUFF_SIZE)
		ft_flush_out(data);
	data->buff[data->count_buff] = c;
	data->count_buff++;
}
