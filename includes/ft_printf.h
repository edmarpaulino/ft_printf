/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:36 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 16:13:53 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // REMOVE IT LATER
# include <stdarg.h>
# include "../includes/libft.h"

# define UPPER_HEX	"0123456789ABCDEF"
# define LOWER_HEX	"0123456789abcdef"
# define TYPES	"cspdiuxX%"
# define FLAGS	"-0.# +"
# define LEFT	'-'
# define PAD	'0'
# define PRECISION	'.'
# define ALTERNATE	'#'
# define SPACE	' '
# define PLUS	'+'

typedef struct s_flag
{
	char	left;
	int		left_size;
	char	pad;
	int		pad_size;
	char	precision;
	int		precision_size;
	char	alter;
	char	space;
	char	plus;
}				t_flag;

int		ft_printf(const char	*format, ...);
int		ft_vprintf(va_list	ap, char	*format);
int		ft_parser_type(va_list	ap, char	type, t_flag	*flag);
int		ft_type_c(int	c, t_flag	*flag);
int		ft_type_s(char	*s, t_flag	*flag);
int		ft_type_p(size_t	p, t_flag	*flag);
int		ft_type_d(int	n, t_flag	*flag);
int		ft_type_u(unsigned int	u, t_flag	*flag);
int		ft_type_x(unsigned int	x, char	*base, t_flag	*flag);
int		ft_parser_flag(va_list	ap, char	**format);
void	ft_init_flags(t_flag	*flag);
void	ft_get_size(char	*flag, int	*flag_size, char	**format);
int		ft_fill_flag(char	*flag);
int		ft_check_error(char	*start, char	**format, int	len);
int		ft_print_alter(char	*hex, char	*base);

#endif
