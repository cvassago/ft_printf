# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvassago <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 15:12:11 by rmonserr          #+#    #+#              #
#    Updated: 2020/10/31 14:47:16 by cvassago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src/
SRCS = 	ft_parse_flags.c \
		ft_parse_format.c \
		ft_parse_length.c \
		ft_parse_number.c \
		ft_parse_precision.c \
		ft_parse_print.c \
		ft_parse_type.c \
		ft_parse_while.c \
		ft_parse_width.c \
		ft_print_char.c \
		ft_print_double.c \
		ft_print_esc.c \
		ft_print_hex.c \
		ft_print_octal.c \
		ft_print_signed.c \
		ft_print_string.c \
		ft_print_unsigned.c \
		ft_printf.c \
		ft_printf_fd.c \
		ft_putchar_total.c \
		ft_putchar_repeat.c \
		ft_putstr_total.c \
		ft_color.c \
		ft_putstr_out.c \
		ft_flush_out.c \
		ft_print_double_inf_nan.c \
		ft_print_double_minus.c

OBJ_PATH = obj
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes -I./libft/includes
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJS))

FT = ./libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT)
	cp libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of libftprintf:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@
	@# -l $(FT)

clean:
	@make clean -C $(FT)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "libftprintf: \033[1;32mRemoving Objs\033[m"

fclean: clean
	@make fclean -C $(FT)
	@rm -f $(NAME)
	@rm -f test
	@echo "Libftprintf: \033[1;32mRemoving Libftprintf\033[m"

re: fclean all

test: $(NAME) test.c
	@$(CC) $(INCLUDES) -L. -lftprintf test.c -o test

.PHONY: all clean fclean re test
