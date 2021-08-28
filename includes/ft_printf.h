/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:36 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 17:33:24 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../includes/libft.h"

# define UPPER_HEX	"0123456789ABCDEF"
# define LOWER_HEX	"0123456789abcdef"
# define TYPES		"cspdiuxX%"
# define FLAGS		"-0.# +"
# define LEFT		'-'
# define PAD		'0'
# define PRECISION	'.'
# define ALTERNATE	'#'
# define SPACE		' '
# define PLUS		'+'

typedef struct s_flag
{
	char	left;
	char	pad;
	char	precision;
	char	alternate;
	char	space;
	char	plus;
	int		width;
	int		size;
}	t_flag;

typedef struct s_format
{
	char	*str;
	char	*tmp;
	char	sign;
	int		len;
	size_t	str_len;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_vprintf(va_list ap, char *format);
int		ft_parser_type(va_list ap, char type, t_flag *flag, t_format *fmt);
int		ft_type_c(int c, t_flag *flag, t_format *fmt);
int		ft_type_s(char *s, t_flag *flag, t_format *fmt);
int		ft_type_p(size_t p, t_flag *flag, t_format *fmt);
int		ft_type_d(int n, t_flag *flag, t_format *fmt);
int		ft_type_u(unsigned int u, t_flag *flag, t_format *fmt);
int		ft_type_x(unsigned int x, char *base, t_flag *flag, t_format *fmt);
int		ft_parser_flag(va_list ap, char **format);
void	ft_init(t_flag *flag, t_format *fmt);
void	ft_get_size(char *flag, int *flag_size, char **format);
int		ft_fill_flag(char *flag);
int		ft_check_error(char *start, char **format, int len);
void	ft_signal(t_flag *flag, t_format	*fmt);
void	ft_alternate(char *base, t_format *fmt);
void	ft_precision(int *current_size, t_flag *flag);
void	ft_zero_pad(t_flag *flag, t_format	*fmt);
void	ft_left_pad(t_flag *flag, t_format	*fmt);

#endif
