/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:19:01 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/20 09:25:53 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				dec;
	char			temp;
	unsigned int	u_save;

	dec = 1;
	while (n / dec / 10)
		dec *= 10;
	n < 0 ? write(fd, "-", 1) : 0;
	u_save = n < 0 ? -n : n;
	while (dec)
	{
		temp = u_save / dec % 10 + '0';
		write(fd, &temp, 1);
		dec /= 10;
	}
}
