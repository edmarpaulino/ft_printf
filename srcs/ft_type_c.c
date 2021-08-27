/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:42:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 15:30:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_c(int	c, t_flag	*flag)
{
	int	len;

	if (flag->left == TRUE)
	{
		len = write(1, &c, 1);
		len += ft_putnchar(SPACE, flag->left_size);
	}
	else if (flag->pad == TRUE || flag->pad_size > 0)
	{
		len = ft_putnchar(SPACE, flag->pad_size);
		len += write(1, &c, 1);
	}
	else
		len = write(1, &c, 1);
	return (len);
}
