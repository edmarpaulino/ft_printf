/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:36 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:29:31 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../includes/libft.h"

# define UPPER_HEX	"0123456789ABCDEF"
# define LOWER_HEX	"0123456789abcdef"

int	ft_printf(const char	*format, ...);
int	ft_vprintf(va_list	ap, char	*format);
int	ft_parser_type(va_list	ap, char	type);
int	ft_type_c(int	c);
int	ft_type_s(char	*s);
int	ft_type_p(size_t	p);
int	ft_type_d(int	n);
int	ft_type_u(unsigned int	u);
int	ft_type_x(unsigned int	x, char	*base);

#endif
