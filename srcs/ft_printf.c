/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:45 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:23:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_vprintf(va_list	ap, char	*format)
{
	int		len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			len += ft_parser_type(ap, *format);
		}
		else
			len += write(1, &*format, 1);
		++format;
	}
	return (len);
}

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vprintf(ap, (char *)format);
	va_end(ap);
	return (len);
}
