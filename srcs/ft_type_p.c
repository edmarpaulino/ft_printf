/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:15:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/31 09:54:17 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_p(size_t p, t_format *fmt)
{
	fmt->str = ft_convert_base(p, LOWER_HEX);
	if (!fmt->str)
		return (FALSE);
	ft_alternate(LOWER_HEX, fmt);
	fmt->str_len = ft_strlen(fmt->str);
	if (fmt->left == FALSE)
	{
		if (fmt->width > 0)
		{
			if (fmt->plus || fmt->space)
				fmt->width--;
			fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->str_len));
		}
		ft_print_signal(fmt);
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
	else
	{
		ft_print_signal(fmt);
		fmt->len += write(1, fmt->str, fmt->str_len);
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->str_len));
	}
	free(fmt->str);
	return (fmt->len);
}
