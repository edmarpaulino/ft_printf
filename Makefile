# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 09:05:06 by edpaulin          #+#    #+#              #
#    Updated: 2021/08/29 15:04:38 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

SRC				=	srcs/ft_printf.c \
					srcs/ft_parser_type.c \
					srcs/ft_type_c.c \
					srcs/ft_type_s.c \
					srcs/ft_type_p.c \
					srcs/ft_type_d.c \
					srcs/ft_type_u.c \
					srcs/ft_type_x.c \
					srcs/ft_parser_flag.c \
					srcs/ft_format.c \
					libft/ft_strlen.c \
					libft/ft_nbrlen.c \
					libft/ft_uitoa.c \
					libft/ft_convert_base.c \
					libft/ft_skip_atoi.c \
					libft/ft_putnchar.c \
					libft/ft_isdigit.c \
					libft/ft_strjoin.c \
					libft/ft_strlcpy.c
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
