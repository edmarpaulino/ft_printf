/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:35:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 17:54:33 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_x_lower(va_list	ap)
{
	size_t	nbr;
	int		len;
	char	*hex_nbr;

	nbr = va_arg(ap, size_t);
	len = 0;	
	hex_nbr = ft_convert_base(nbr, LOWER_HEX);
	if (hex_nbr)
	{
		ft_putstr(hex_nbr);
		len = ft_strlen(hex_nbr);
		free(hex_nbr);
	}
	return (len);
}
