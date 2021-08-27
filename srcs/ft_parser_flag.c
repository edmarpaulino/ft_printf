/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 16:24:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//	CAPTURE THE FLAG

void	ft_init_flags(t_flag	*flag)
{
	flag->left = FALSE;
	flag->left_size = 0;
	flag->pad = FALSE;
	flag->pad_size = 0;
	flag->precision = FALSE;
	flag->precision_size = 0;
	flag->alter = FALSE;
	flag->space = FALSE;
	flag->plus = FALSE;
}

void	ft_get_size(char	*flag, int	*flag_size, char	**format)
{
	*flag = TRUE;
	++(*format);
	*flag_size = ft_skip_atoi(format);
	--(*format);
}

int	ft_parser_flag(va_list	ap, char	**format)
{
	t_flag	flag;

	ft_init_flags(&flag);
	while (ft_strchr(FLAGS, **format) || ft_isdigit(**format))
	{
		if (**format == LEFT)
			ft_get_size(&flag.left, &flag.left_size, format);
		else if (ft_isdigit(**format))
		{
			if (**format == PAD)
				flag.pad = TRUE;
			flag.pad_size = ft_skip_atoi(format);
			--(*format);
		}
		else if (**format == PRECISION)
			ft_get_size(&flag.precision, &flag.precision_size, format);
		else if (**format == ALTERNATE)
			flag.alter = TRUE;
		else if (**format == SPACE)
			flag.space = TRUE;
		else if (**format == PLUS)
			flag.plus = TRUE;
		++(*format);
	}
	return (ft_parser_type(ap, **format, &flag));
}
