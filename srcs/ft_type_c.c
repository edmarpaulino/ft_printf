/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:42:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:44:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_c(int c, t_format *fmt)
{
	if (fmt->left == TRUE)
	{
		fmt->len += write(1, &c, 1);
		fmt->len += ft_putnchar(SPACE, --fmt->width);
	}
	else if (fmt->width > 0)
	{
		fmt->len += ft_putnchar(SPACE, --fmt->width);
		fmt->len += write(1, &c, 1);
	}
	else
		fmt->len += write(1, &c, 1);
	return (fmt->len);
}
