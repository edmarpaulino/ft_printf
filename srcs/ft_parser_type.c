/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:17:33 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 17:56:28 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parser_type(va_list	ap, char	flag)
{
	if (flag == 'c')
		return (ft_type_c(ap));
	else if (flag == 's')
		return (ft_type_s(ap));
	else if (flag == 'p')
		return (ft_type_p(ap));
	else if (flag == 'd' || flag == 'i')
		return (ft_type_d(ap));
	else if (flag == 'u')
		return (ft_type_u(ap));
	else if (flag == 'x')
		return (ft_type_x_lower(ap));
	else if (flag == 'X')
		return (ft_type_x_upper(ap));
	return (0);
}
