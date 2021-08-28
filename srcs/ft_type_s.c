/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:52:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 12:05:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_s(char *s, t_flag *flag, t_format *fmt)
{
	int	s_len;

	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (flag->precision == TRUE && flag->size < s_len)
		s_len = flag->size;
	if (flag->left == TRUE)
	{
		fmt->len += write(1, s, s_len);
		fmt->len += ft_putnchar(SPACE, (flag->width - s_len));
	}
	else if (flag->pad == TRUE || flag->width > 0)
	{
		fmt->len += ft_putnchar(SPACE, (flag->width - s_len));
		fmt->len += write(1, s, s_len);
	}
	else
		fmt->len += write(1, s, s_len);
	return (fmt->len);
}
