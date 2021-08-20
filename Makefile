# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 09:05:06 by edpaulin          #+#    #+#              #
#    Updated: 2021/08/20 18:36:22 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

SRC				=	srcs/ft_printf.c \
					srcs/ft_vprintf.c \
					srcs/ft_parser_type.c \
					srcs/ft_type_c.c \
					srcs/ft_type_s.c \
					srcs/ft_type_p.c \
					srcs/ft_type_d.c \
					srcs/ft_type_u.c \
					srcs/ft_type_x_lower.c \
					srcs/ft_type_x_upper.c \
					libft/ft_putchar.c \
					libft/ft_strlen.c \
					libft/ft_putstr.c \
					libft/ft_nbrlen.c \
					libft/ft_unbrlen.c \
					libft/ft_itoa.c \
					libft/ft_uitoa.c \
					libft/ft_strdup.c \
					libft/ft_strlcpy.c \
					libft/ft_convert_base.c
SRC_BONUS		=	
OBJ				=	$(SRC:.c=.o)
OBJ_BONUS		=	$(SRC_BONUS:.c=.o)
	
HEADER_DIR		=	includes
	
CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror

.DEFAULT_GOAL	=	all

all:		$(NAME)

bonus:		$(NAME) $(OBJ_BONUS)
	ar cr $(NAME) $(OBJ) $(OBJ_BONUS)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME):	$(OBJ)
	ar cr $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

rebonus:	fclean bonus
