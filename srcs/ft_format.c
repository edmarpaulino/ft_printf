/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:52:27 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/31 10:18:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_signal(t_format *fmt)
{
	int	ret;

	ret = 0;
	if (fmt->minus == TRUE)
		ret = write(1, "-", 1);
	else if (fmt->plus == TRUE)
		ret = write(1, "+", 1);
	else if (fmt->space == TRUE)
		ret = write(1, " ", 1);
	fmt->len += ret;
	return (ret);
}

void	ft_alternate(char *base, t_format *fmt)
{
	if (base[10] == 'a')
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("0x", fmt->tmp);
		free(fmt->tmp);
	}
	else if (base[10] == 'A')
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("0X", fmt->tmp);
		free(fmt->tmp);
	}
}

void	ft_left_pad(t_format *fmt)
{
	if (fmt->precision == TRUE && fmt->size >= fmt->width)
		ft_zero_pad(fmt);
	else if (fmt->precision == TRUE && fmt->size > 0)
	{
		ft_print_signal(fmt);
		fmt->len += ft_putnchar(PAD, (fmt->size - fmt->str_len));
		fmt->len += write(1, fmt->str, fmt->str_len);
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
	}
	else
	{
		ft_print_signal(fmt);
		if (fmt->str[0] == '0' && fmt->precision == TRUE && fmt->size == 0)
			fmt->str[0] = ' ';
		fmt->len += write(1, fmt->str, fmt->str_len);
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
	}
}

int	ft_precision(int *sign, t_format *fmt)
{
	int	aux;

	aux = fmt->width;
	if (fmt->precision == TRUE && fmt->width < fmt->size)
		fmt->width = fmt->size;
	if (fmt->precision == TRUE)
	{
		if (fmt->size < (int)fmt->str_len)
			aux = fmt->str_len;
		else
			aux = fmt->size;
		fmt->len += ft_putnchar(SPACE, (fmt->width - aux - *sign));
		if (fmt->size > 0)
			*sign = 0;
	}
	return (aux);
}

void	ft_zero_pad(t_format *fmt)
{
	int	sign;
	int	aux;

	sign = 0;
	if (fmt->minus == TRUE || fmt->plus == TRUE || fmt->space == TRUE)
		sign = 1;
	if (fmt->pad == TRUE || fmt->precision == TRUE)
	{
		aux = ft_precision(&sign, fmt);
		ft_print_signal(fmt);
		fmt->len += ft_putnchar(PAD, (aux - sign - fmt->str_len));
		if (fmt->str[0] == '0' && fmt->precision == TRUE && fmt->size == 0)
			fmt->str[0] = ' ';
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
	else if (fmt->width > 0)
	{
		fmt->len += ft_putnchar(SPACE, (fmt->width - sign - fmt->str_len));
		ft_print_signal(fmt);
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
}
