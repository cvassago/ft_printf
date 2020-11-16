/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:18:45 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/18 19:18:50 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int				dec;
	char			temp;
	unsigned int	u_save;

	dec = 1;
	while (n / dec / 10)
		dec *= 10;
	n < 0 ? write(1, "-", 1) : 0;
	u_save = n < 0 ? -n : n;
	while (dec)
	{
		temp = u_save / dec % 10 + '0';
		write(1, &temp, 1);
		dec /= 10;
	}
}
