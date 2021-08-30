/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:17:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 11:35:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parser_type(va_list ap, char type, t_format *fmt)
{
	if (type == '%')
		return (write(1, "%", 1));
	else if (type == 'c')
		return (ft_type_c(va_arg(ap, int), fmt));
	else if (type == 's')
		return (ft_type_s(va_arg(ap, char *), fmt));
	else if (type == 'p')
		return (ft_type_p(va_arg(ap, size_t), fmt));
	else if (type == 'd' || type == 'i')
		return (ft_type_d(va_arg(ap, int), fmt));
	else if (type == 'u')
		return (ft_type_u(va_arg(ap, unsigned int), fmt));
	else if (type == 'x')
		return (ft_type_x(va_arg(ap, unsigned int), LOWER_HEX, fmt));
	else if (type == 'X')
		return (ft_type_x(va_arg(ap, unsigned int), UPPER_HEX, fmt));
	return (ERROR);
}
