/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:06:27 by cvassago          #+#    #+#             */
/*   Updated: 2020/10/31 15:04:59 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdio.h"

# include <stdarg.h>
# include <ctype.h>
# include <float.h>
# include "libft.h"

# define TEMP_SIZE 2048
# define FT_BUFF_SIZE 2048

typedef enum	e_length
{
	LENGTH_NONE,
	LENGTH_H,
	LENGTH_HH,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_CAP_L
}				t_length;

typedef struct	s_params
{
	va_list		args;
	char		*format;
	long int	precision;
	long int	width;
	int			minus_sign;
	int			plus_sign;
	int			space;
	int			zero;
	int			hash;
	size_t		size;
	int			counter;
	int			total;
	int			negative;
	int			fd;
	char		type;
	char		buff[FT_BUFF_SIZE];
	size_t		count_buff;
	char		tmp[TEMP_SIZE];
}				t_params;

int				ft_printf(char *format, ...);
int				ft_printf_fd(int fd, char *format, ...);

void			ft_color(t_params *data);

void			ft_parse_while(t_params *data);
void			ft_parse_format(t_params *data);
int				ft_parse_flags(t_params *data);
int				ft_parse_width(t_params *data);
int				ft_parse_number(t_params *data);
int				ft_parse_precision(t_params *data);
int				ft_parse_length(t_params *data);
int				ft_parse_type(t_params *data);
int				ft_parse_print(t_params *data);

void			ft_print_char(t_params *data);
void			ft_print_string(t_params *data);
void			ft_print_hex(t_params *data);
void			ft_print_octal(t_params *data);
void			ft_print_signed(t_params *data);
void			ft_print_unsigned(t_params *data);
void			ft_print_esc(t_params *data);
void			ft_print_double(t_params *data);
int				ft_inf_nan(t_params *data, double long arg);
int				ft_sign(float val);

void			ft_putchar_repeat(t_params *data, char c, int n);
void			ft_putstr_total(t_params *data, const char *str, int n);
void			ft_flush_out(t_params *data);
void			ft_putstr_out(t_params *data, const char *s);
void			ft_putchar_total(t_params *data, char c);

#endif
