/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:15:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 12:05:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_p(size_t p, t_flag *flag, t_format	*fmt)
{
	fmt->tmp = ft_convert_base(p, LOWER_HEX);
	if (!fmt->tmp)
		return (FALSE);
	fmt->str = ft_strjoin("0x", fmt->tmp);
	free(fmt->tmp);
	fmt->str_len = ft_strlen(fmt->str);
	if (flag->left == FALSE)
	{
		if (flag->width > 0)
			fmt->len += ft_putnchar(SPACE, (flag->width - fmt->str_len));
		ft_signal(flag, fmt);
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
	else
	{
		fmt->len += write(1, fmt->str, fmt->str_len);
		fmt->len += ft_putnchar(SPACE, (flag->width - fmt->str_len));
	}
	free(fmt->str);
	return (fmt->len);
}
