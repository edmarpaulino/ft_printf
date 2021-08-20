/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:36 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 17:57:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../includes/libft.h"

# define UPPER_HEX	"0123456789ABCDEF"
# define LOWER_HEX	"0123456789abcdef"

typedef struct s_flags
{
	char	left;
	char	padding;
	int		precision;
	char	alternate;
	char	space;
	char	plus;
}				t_flags;

int	ft_printf(const char	*format, ...);
int	ft_vprintf(va_list	ap, char	*format);
int	ft_parser_type(va_list	ap, char	flag);
int	ft_type_c(va_list ap);
int	ft_type_s(va_list ap);
int	ft_type_p(va_list ap);
int	ft_type_d(va_list ap);
int	ft_type_u(va_list ap);
int	ft_type_x_lower(va_list ap);
int	ft_type_x_upper(va_list ap);

#endif
