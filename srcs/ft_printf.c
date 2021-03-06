/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:45 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/31 10:20:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_error(char *start, char **format, int len)
{
	if (len == ERROR)
	{
		*format = start;
		len = write(1, *format, ft_strlen(*format));
		*format += (len - 1);
	}
	return (len);
}

int	ft_vprintf(va_list ap, char *format)
{
	int		len;
	char	*start;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			start = format;
			++format;
			len += ft_check_error(start, &format, ft_parser_flag(ap, &format));
		}
		else
			len += write(1, &*format, 1);
		++format;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vprintf(ap, (char *)format);
	va_end(ap);
	return (len);
}
