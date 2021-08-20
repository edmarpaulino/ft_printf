/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:34:37 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 14:02:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_vprintf(va_list	ap, char	*format)
{
	int		len;
	char	*str;

	len = 0;
	str = format;
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			if (*str == '%')
			{
				ft_putchar(*str);
				++len;
			}
			else
				len += ft_parser_type(ap, *str);
		}
		else
		{
			ft_putchar(*str);
			++len;
		}
		++str;
	}
	return (len);
}
