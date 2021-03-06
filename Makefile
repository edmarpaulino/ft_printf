# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 09:05:06 by edpaulin          #+#    #+#              #
#    Updated: 2021/08/31 11:42:32 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

LIBFT			=	libft/libft.a

SRC				=	srcs/ft_printf.c \
					srcs/ft_parser_type.c \
					srcs/ft_type_c.c \
					srcs/ft_type_s.c \
					srcs/ft_type_p.c \
					srcs/ft_type_d.c \
					srcs/ft_type_u.c \
					srcs/ft_type_x.c \
					srcs/ft_parser_flag.c \
					srcs/ft_format.c 
OBJ				=	$(SRC:.c=.o)

HEADER_DIR		=	includes

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror

.DEFAULT_GOAL	=	all

all:		$(NAME)

bonus:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(NAME):	$(LIBFT) $(OBJ)
	ar cr $(NAME) $(OBJ)

$(LIBFT):
	make all -C libft
	cp $(LIBFT) $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:		clean
	make fclean -C libft
	rm -f $(NAME)

re:			fclean all

rebonus:	fclean bonus
