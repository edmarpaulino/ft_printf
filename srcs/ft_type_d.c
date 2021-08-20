/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 14:54:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_d(va_list	ap)
{
	int		nbr;
	int		len;
	char	*str;

	len = 0;
	nbr = va_arg(ap, int);
	str = ft_itoa(nbr);
	if (str)
	{
		len = ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (len);
}
