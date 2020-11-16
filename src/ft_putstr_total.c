/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_total.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:03:21 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/29 20:03:23 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_total(t_params *data, const char *str, int n)
{
	while (n-- > 0 && *str)
	{
		ft_putchar_total(data, *str);
		str++;
	}
}
