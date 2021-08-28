/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:52:27 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 17:34:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_signal(t_flag *flag, t_format *fmt)
{
	if (flag->plus == TRUE && fmt->sign == FALSE)
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("+", fmt->tmp);
		free(fmt->tmp);
	}
	else if (flag->space == TRUE && fmt->sign == FALSE)
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin(" ", fmt->tmp);
		free(fmt->tmp);
	}
	fmt->str_len = ft_strlen(fmt->str);
}

void	ft_alternate(char *base, t_format *fmt)
{
	if (!ft_strcmp(base, LOWER_HEX))
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("0x", fmt->tmp);
		free(fmt->tmp);
	}
	else
	{
		fmt->tmp = fmt->str;
		fmt->str = ft_strjoin("0X", fmt->tmp);
		free(fmt->tmp);
	}
}

void	ft_precision(int *current_size, t_flag *flag)
{
	if (flag->precision == TRUE && *current_size < flag->size)
		*current_size = flag->size;
}

void	ft_zero_pad(t_flag *flag, t_format	*fmt)
{
	char	c;

	if (flag->precision == TRUE && fmt->sign == TRUE)
		flag->size++;
	ft_precision(&flag->width, flag);
	if ((flag->pad == TRUE && fmt->str[0] != '0') \
		|| (flag->precision == TRUE && flag->size > 0))
		c = PAD;
	else
		c = SPACE;
	if (flag->precision == TRUE && flag->size > 0 && flag->width > flag->size)
	{
		if (flag->size > (int)fmt->str_len)
			fmt->len += ft_putnchar(SPACE, (flag->width - flag->size));
		else
			fmt->len += ft_putnchar(SPACE, (flag->width - fmt->str_len - fmt->sign));
		flag->width -= fmt->len;
	}
	if (fmt->sign == TRUE && c == PAD)
	{
		fmt->len += write(1, "-", 1);
		fmt->len += ft_putnchar(c, (flag->width - (ft_strlen(fmt->str) + 1)));
	}
	else if (fmt->sign == TRUE && c == SPACE)
	{
		fmt->len += ft_putnchar(c, (flag->width - (ft_strlen(fmt->str) + 1)));
		fmt->len += write(1, "-", 1);
	}
	else
	{
		if (fmt->str[0] != '0')
			fmt->len += ft_putnchar(c, (flag->width - ft_strlen(fmt->str)));
		else if (fmt->str[0] == '0' && flag->precision == FALSE)
			fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
		else
			fmt->len += ft_putnchar(c, (flag->width));
	}
	if (fmt->str[0] != '0')
		fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
}

void	ft_left_pad(t_flag *flag, t_format	*fmt)
{
	if (flag->precision == TRUE && flag->size >= flag->width)
		ft_zero_pad(flag, fmt);
	else
	{
		if (fmt->sign == TRUE)
			fmt->len += write(1, "-", 1);
		if (flag->precision == TRUE && flag->size > 0)
			fmt->len += ft_putnchar(PAD, (flag->size - fmt->str_len));
		if (fmt->str[0] == '0' && flag->width > 0 \
			&& flag->precision == TRUE && flag->size == 0)
			fmt->len += ft_putnchar(SPACE, (flag->width - fmt->len));
		else
		{
			fmt->len += write(1, fmt->str, ft_strlen(fmt->str));
			fmt->len += ft_putnchar(SPACE, (flag->width - fmt->len));
		}
	}
}
