/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:35:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/21 13:21:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_x_upper(va_list	ap)
{
	unsigned int	nbr;
	int				len;
	char			*hex_nbr;

	nbr = va_arg(ap, unsigned int);
	len = 0;
	hex_nbr = ft_convert_base(nbr, UPPER_HEX);
	if (hex_nbr)
	{
		ft_putstr(hex_nbr);
		len = ft_strlen(hex_nbr);
		free(hex_nbr);
	}
	return (len);
}
