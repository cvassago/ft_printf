/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:00:37 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:00:40 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_flush_out(t_params *data)
{
	ssize_t		ret;

	if ((ret = write(1, data->buff, data->count_buff)) > 0)
		data->total += (int)ret;
	data->count_buff = 0;
}
