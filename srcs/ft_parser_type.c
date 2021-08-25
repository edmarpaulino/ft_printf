/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:17:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:18:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parser_type(va_list	ap, char	type)
{
	if (type == '%')
		return (write(1, "%", 1));
	else if (type == 'c')
		return (ft_type_c(va_arg(ap, int)));
	else if (type == 's')
		return (ft_type_s(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_type_p(va_arg(ap, size_t)));
	else if (type == 'd' || type == 'i')
		return (ft_type_d(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_type_u(va_arg(ap, unsigned int)));
	else if (type == 'x')
		return (ft_type_x(va_arg(ap, unsigned int), LOWER_HEX));
	else if (type == 'X')
		return (ft_type_x(va_arg(ap, unsigned int), UPPER_HEX));
	return (0);
}
