/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:15:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 18:23:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_p(va_list	ap)
{
	size_t	ptr;
	int		len;
	char	*addr;

	ptr = va_arg(ap, size_t);
	len = 0;
	addr = ft_convert_base(ptr, LOWER_HEX);
	if (addr)
	{
		ft_putstr("0x");
		ft_putstr(addr);
		len = (ft_strlen(addr) + 2);
		free(addr);
	}
	return (len);
}
