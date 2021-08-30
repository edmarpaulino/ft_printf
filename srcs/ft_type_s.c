/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:52:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:45:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_s(char *s, t_format *fmt)
{
	if (!s)
		s = "(null)";
	fmt->str_len = ft_strlen(s);
	if (fmt->precision == TRUE && fmt->size < (int)fmt->str_len)
		fmt->str_len = fmt->size;
	if (fmt->left == TRUE)
	{
		fmt->len += write(1, s, fmt->str_len);
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->str_len));
	}
	else if (fmt->pad == TRUE || fmt->width > 0)
	{
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->str_len));
		fmt->len += write(1, s, fmt->str_len);
	}
	else
		fmt->len += write(1, s, fmt->str_len);
	return (fmt->len);
}
