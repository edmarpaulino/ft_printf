/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 18:22:07 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_d(int d, t_format	*fmt)
{
	if (fmt->precision == TRUE && fmt->size == 0 && d == 0 && fmt->width == 0)
	{
		ft_print_signal(fmt);
		return (fmt->len);
	}
	if (d < 0)
	{
		fmt->str = ft_uitoa(-(long)d);
		fmt->sign = TRUE;
	}
	else
		fmt->str = ft_uitoa(d);
	if (!fmt->str)
		return (ERROR);
	fmt->str_len = ft_strlen(fmt->str);
	if (fmt->left == TRUE)
		ft_left_pad(fmt);
	else if (fmt->precision == TRUE || fmt->width > 0)
		ft_zero_pad(fmt);
	else
	{
		ft_print_signal(fmt);
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
	}
	free(fmt->str);
	return (fmt->len);
}
