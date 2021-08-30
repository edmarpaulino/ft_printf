/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:35:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 11:06:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_x(unsigned int x, char *base, t_format *fmt)
{
	if (fmt->precision == TRUE && fmt->size == 0 \
		&& x == 0 && fmt->width == 0) // If don't I use this? what will happen?
		return (FALSE);
	fmt->str = ft_convert_base(x, base);
	if (!fmt->str)
		return (ERROR);
	if (fmt->alternate == TRUE && x != 0)
		ft_alternate(base, fmt);
	else
		ft_signal(fmt);
	if (fmt->left == TRUE)
		ft_left_pad(fmt);
	else if (fmt->precision == TRUE || fmt->width > 0)
		ft_zero_pad(fmt);
	else
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
	free(fmt->str);
	return (fmt->len);
}
