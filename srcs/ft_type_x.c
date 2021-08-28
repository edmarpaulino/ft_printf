/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:35:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 17:43:02 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_x(unsigned int x, char *base, t_flag *flag, t_format *fmt)
{
	fmt->str = ft_convert_base(x, base);
	if (!fmt->str || !flag)
		return (ERROR);
	if (flag->alternate == TRUE && x != 0)
		ft_alternate(base, fmt);
	else
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
