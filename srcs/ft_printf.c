/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:05:45 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 11:03:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_vprintf(ap, (char *)format);
	va_end(ap);
	return (len);
}
