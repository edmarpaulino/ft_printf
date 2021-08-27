/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 19:13:22 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
char	*ft_signal(char	*str, char	sign, t_flag *flag)
{
	char	*tmp;

	if (flag->plus == TRUE && sign == FALSE)
	{
		tmp = str;
		str = ft_strjoin("+", tmp);
		free(tmp);
	}
	else if (flag->space == TRUE && sign == FALSE)
	{
		tmp = str;
		str = ft_strjoin(" ", tmp);
		free(tmp);
	}
	return (str);
}

void	ft_precision(int	*current_size, t_flag	*flag)
{
	if (flag->precision == TRUE && *current_size < flag->precision_size)
		*current_size = flag->precision_size;
}

int	ft_zero_pad(char	*str, char	sign, t_flag *flag)
{
	int		len;
	char	c;
	
	ft_precision(&flag->pad_size, flag);
	if (flag->pad == TRUE || flag->precision == TRUE)
		c = PAD;
	else
		c = SPACE;
	if (sign == TRUE && c == PAD)
	{
		len = write(1, "-", 1);
		len += ft_putnchar(c, ((flag->pad_size ) - ft_strlen(str)));
	}
	else if (sign == TRUE && c == SPACE)
	{
		len = ft_putnchar(c, ((flag->pad_size) - ft_strlen(str)));
		len += write(1, "-", 1);
	}
	else
		len = ft_putnchar(c, ((flag->pad_size + 1) - ft_strlen(str)));
	len += write(1, str, ft_strlen(str));
	return (len);
}

int	ft_left_pad(char	*str, char	sign, t_flag *flag)
{
	int	len;

	len = 0;
	if (flag->precision == TRUE && flag->precision_size > flag->left_size)
		len += ft_zero_pad(str, sign, flag);
	else
	{
		if (sign == TRUE)
			len = write(1, "-", 1);
		if (str[0] == '0' && flag->left_size > 0)
			len += ft_putnchar(SPACE, ((flag->left_size + 2) - len));
		else
		{
			len += write(1, str, ft_strlen(str));
			len += ft_putnchar(SPACE, ((flag->left_size + 1) - len));
		}
	}
	return (len);
}

int	ft_type_d(int	d, t_flag	*flag)
{
	int		len;
	char	*str;
	char	sign;

	len = 0;
	sign = FALSE;
	if (flag->precision == TRUE && flag->precision_size == 0 && d == 0 && flag->pad_size == 0 && flag->left_size == 0)
		return (FALSE);
	if (d < 0)
	{
		str = ft_uitoa(-(long)d);
		sign = TRUE;
	}
	else
		str = ft_uitoa(d);
	if (!str)
		return (ERROR);
	str = ft_signal(str, sign, flag);
	if (flag->left == TRUE)
		len = ft_left_pad(str, sign, flag);
	else if (flag->precision == TRUE || flag->pad == TRUE || flag->pad_size > 0)
		len = ft_zero_pad(str, sign, flag);
	else
	{
		if (sign == TRUE)
			len = write(1, "-", 1);
		len += write(1, str, ft_strlen(str));
	}
	free(str);
	return (len);
}
