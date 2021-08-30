/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:52:27 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 15:42:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_signal(t_format *fmt)
{
	if (fmt->sign == TRUE)
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("-", fmt->tmp);
		free(fmt->tmp);
	}
	else if (fmt->plus == TRUE)
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("+", fmt->tmp);
		free(fmt->tmp);
	}
	else if (fmt->space == TRUE)
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin(" ", fmt->tmp);
		free(fmt->tmp);
	}
	fmt->str_len = ft_strlen(fmt->str);
}

void	ft_print_signal(t_format *fmt)
{
	if (fmt->sign == TRUE)
		fmt->len += write(1, "-", 1);
	else if (fmt->plus == TRUE)
		fmt->len += write(1, "+", 1);
	else if (fmt->space == TRUE)
		fmt->len += write(1, " ", 1);
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

void	ft_precision(int *current_size, t_format *fmt)
{
	if (fmt->precision == TRUE && *current_size < fmt->size)
		*current_size = fmt->size;
}

void	ft_left_pad(t_format *fmt)
{
	if (fmt->precision == TRUE && fmt->size >= fmt->width)
		ft_zero_pad(fmt);
	else if (fmt->precision == TRUE && fmt->size > 0)
	{
		ft_print_signal(fmt);
		fmt->len += ft_putnchar(PAD, (fmt->size - fmt->str_len));
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
	}
	else
	{
		ft_signal(fmt);
		if (fmt->precision == TRUE && fmt->size > 0)
			fmt->len += ft_putnchar(PAD, (fmt->size - fmt->str_len));
		if (fmt->str[0] == '0' && fmt->precision == TRUE && fmt->size == 0)
			fmt->str[0] = ' ';
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
	}
}

void	ft_zero_pad(t_format *fmt)
{
	int	sign_size;
	int	aux;

	sign_size = 0;
	aux = 0;
	if (fmt->sign == TRUE || fmt->plus == TRUE || fmt->space == TRUE)
		sign_size = 1;
	if (fmt->pad == TRUE || fmt->precision == TRUE)
	{
		aux = fmt->width;
		ft_precision(&fmt->width, fmt);
		if (fmt->precision == TRUE)
		{
			if (fmt->size < (int)fmt->str_len)
				aux = fmt->str_len;
			else
				aux = fmt->size;
			fmt->len += ft_putnchar(SPACE, (fmt->width - aux - sign_size));
			if (fmt->size > 0)
				sign_size = 0;
		}
		ft_print_signal(fmt);
		fmt->len += ft_putnchar(PAD, (aux - sign_size - fmt->str_len));
		if (fmt->str[0] == '0' && fmt->precision == TRUE && fmt->size == 0)
			fmt->str[0] = ' ';
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
	else if (fmt->width > 0)
	{
		fmt->len += ft_putnchar(SPACE, (fmt->width - sign_size - fmt->str_len));
		ft_print_signal(fmt);
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
}
