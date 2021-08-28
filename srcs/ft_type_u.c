/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 17:33:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_u(unsigned int u, t_flag *flag, t_format *fmt)
{
	if (flag->precision == TRUE && flag->size == 0 \
		&& u == 0 && flag->width == 0 && flag->width == 0)
		return (FALSE);
	fmt->str = ft_uitoa(u);
	if (!fmt->str)
		return (ERROR);
	ft_signal(flag, fmt);
	if (flag->left == TRUE)
		ft_left_pad(flag, fmt);
	else if (flag->precision == TRUE || flag->pad == TRUE || flag->width > 0)
		ft_zero_pad(flag, fmt);
	else
	{
		if (fmt->sign == TRUE)
			fmt->len += write(1, "-", 1);
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
	}
	free(fmt->str);
	return (fmt->len);
}
