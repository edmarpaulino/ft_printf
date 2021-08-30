/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:52:27 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/30 13:53:40 by edpaulin         ###   ########.fr       */
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

void	ft_left_pad(t_format	*fmt)
{
	if (fmt->precision == TRUE && fmt->size >= fmt->width)
		ft_zero_pad(fmt);
	else if (fmt->precision == TRUE && fmt->size > 0)
	{
		if (fmt->sign == TRUE)
			fmt->len += write(1, "-", 1);
		else if (fmt->plus == TRUE)
			fmt->len += write(1, "+", 1);
		else if (fmt->space == TRUE)
			fmt->len += write(1, " ", 1);
		fmt->len += ft_putnchar(PAD, (fmt->size - fmt->str_len));
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
	}
	else
	{
		ft_signal(fmt);
		if (fmt->precision == TRUE && fmt->size > 0)
			fmt->len += ft_putnchar(PAD, (fmt->size - fmt->str_len));
		if (fmt->str[0] == '0' && fmt->width > 0 \
			&& fmt->precision == TRUE && fmt->size == 0)
			fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
		else
		{
			fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
			fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len));
		}
	}
}

void	ft_zero_pad(t_format	*fmt)
{
	int	sign_size;
	int	aux;
	int	test;

	sign_size = 0;
	aux = 0;
	test = 0;
	if (fmt->pad == TRUE || fmt->precision == TRUE)
	{
		aux = fmt->width;
		if (fmt->sign == TRUE || fmt->plus == TRUE || fmt->space == TRUE)
			sign_size = 1;
		if (fmt->size > 0)
			sign_size = 0;
		ft_precision(&fmt->width, fmt);
		if (fmt->precision == TRUE)
		{
			if (fmt->size < (int)fmt->str_len)
				aux = fmt->str_len;
			else
			{
				aux = fmt->size;
			}
			if (sign_size == 0 && (fmt->sign == TRUE || fmt->plus == TRUE || fmt->space == TRUE))
				test = 1;
			fmt->len += ft_putnchar(SPACE, (fmt->width - aux - sign_size - test));
		}
		if (fmt->sign == TRUE)
			fmt->len += write(1, "-", 1);
		else if (fmt->plus == TRUE)
			fmt->len += write(1, "+", 1);
		else if (fmt->space == TRUE)
			fmt->len += write(1, " ", 1);
		fmt->len += ft_putnchar(PAD, (aux - sign_size - fmt->str_len));
		if (fmt->str[0] == '0' && fmt->precision == TRUE && fmt->size == 0)
			fmt->len += write(1, " ", 1);
		else
			fmt->len += write(1, fmt->str, fmt->str_len);
	}
	else if (fmt->width > 0)
	{
		if (fmt->sign == TRUE || fmt->plus == TRUE || fmt->space == TRUE)
				fmt->len++;
		fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->len - fmt->str_len));
		if (fmt->sign == TRUE)
			write(1, "-", 1);
		else if (fmt->plus == TRUE)
			write(1, "+", 1);
		else if (fmt->space == TRUE)
			write(1, " ", 1);
		fmt->len += write(1, fmt->str, fmt->str_len);
	}
}

/*
	char	c;

	if (fmt->precision == TRUE && fmt->sign == TRUE) // can be fmt->size += fmt->sign
		fmt->size++;
	ft_precision(&fmt->width, fmt); // can I optimize this?
	if ((fmt->pad == TRUE && fmt->str[0] != '0') \
		|| (fmt->precision == TRUE && fmt->size > 0)) // I think that this is redundant, do I really need this?
		c = PAD;
	else
		c = SPACE;
	if (fmt->precision == TRUE && fmt->size > 0 && fmt->width > fmt->size) // why I need this? Can I optimize this?
	{
		if (fmt->size > (int)fmt->str_len)
			fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->size));
		else
			fmt->len += ft_putnchar(SPACE, (fmt->width - fmt->str_len - fmt->sign));
		fmt->width -= fmt->len;
	}
	if (fmt->sign == TRUE && c == PAD) // can I optimize the signal pad conditions?
	{
		fmt->len += write(1, "-", 1);
		fmt->len += ft_putnchar(c, (fmt->width - (ft_strlen(fmt->str) + 1)));
	}
	else if (fmt->sign == TRUE && c == SPACE)
	{
		fmt->len += ft_putnchar(c, (fmt->width - (ft_strlen(fmt->str) + 1)));
		fmt->len += write(1, "-", 1);
	}
	else // I think that has something wrong with this else and the 0 number check
	{
		if (fmt->str[0] != '0')
			fmt->len += ft_putnchar(c, (fmt->width - ft_strlen(fmt->str)));
		else if (fmt->str[0] == '0' && fmt->precision == FALSE)
			fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
		else
			fmt->len += ft_putnchar(c, (fmt->width));
	}
	if (fmt->str[0] != '0') // %012d LONG_MIN -> doesn't work
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
*/
