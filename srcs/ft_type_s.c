/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ss                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:52:35 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/26 16:39:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_s(char	*s, t_flag	*flag)
{
	int	len;
	int	s_len;

	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (flag->precision == TRUE && flag->precision_size < s_len)
		s_len = flag->precision_size;
	if (flag->left == TRUE)
	{
		len = write(1, s, s_len);
		len += ft_putnchar(SPACE, (flag->left_size - s_len + 1));
	}
	else if (flag->pad == TRUE || flag->pad_size > 0)
	{
		len = ft_putnchar(SPACE, (flag->pad_size - s_len + 1));
		len += write(1, s, s_len);
	}
	else
		len = write(1, s, s_len);
	return (len);
}
