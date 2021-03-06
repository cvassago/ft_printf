/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:17:57 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/31 15:19:21 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sign(float val)
{
	return (((((unsigned char*)&(val))[sizeof(float) - 1]) >> 7) == 1 &&
			val == 0);
}
