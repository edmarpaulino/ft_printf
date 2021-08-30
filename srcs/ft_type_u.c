/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 18:20:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_u(unsigned int u, t_format *fmt)
{
	if (fmt->precision == TRUE && fmt->size == 0 && u == 0 && fmt->width == 0)
		return (fmt->len);
	fmt->str = ft_uitoa(u);
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
