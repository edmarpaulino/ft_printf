# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 11:34:28 by edpaulin          #+#    #+#              #
#    Updated: 2021/08/31 11:35:36 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

SRC				=	ft_strlen.c \
					ft_nbrlen.c \
					ft_uitoa.c \
					ft_convert_base.c \
					ft_skip_atoi.c \
					ft_putnchar.c \
					ft_isdigit.c \
					ft_strjoin.c \
					ft_strlcpy.c
OBJ				=	$(SRC:.c=.o)

HEADER_DIR		=	includes

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror

.DEFAULT_GOAL	=	all

all:		$(NAME)

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
