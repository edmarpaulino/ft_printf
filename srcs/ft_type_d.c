/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 10:01:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_d(int d, t_format	*fmt)
{
	if (fmt->precision == TRUE && fmt->size == 0 \
		&& d == 0 && fmt->width == 0) // If don't I use this? what will happen?
		return (FALSE);
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
	// ft_signal(fmt); // if the number has zero pad and plus sign, what happens? -> it's very awful
	if (fmt->left == TRUE)
		ft_left_pad(fmt);
	else if (fmt->precision == TRUE || fmt->width > 0) // Can I optimize this?
		ft_zero_pad(fmt);
	else
	{
		if (fmt->sign == TRUE) // I think that has something redundat here
			fmt->len += write(1, "-", 1);
		else
			ft_signal(fmt);
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
	}
	free(fmt->str);
	return (fmt->len);
}
