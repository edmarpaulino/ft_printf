/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 16:38:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//	CAPTURE THE FLAG

void	ft_init(t_flag *flag, t_format *fmt)
{
	flag->left = FALSE;
	flag->pad = FALSE;
	flag->precision = FALSE;
	flag->alternate = FALSE;
	flag->space = FALSE;
	flag->plus = FALSE;
	flag->width = 0;
	flag->size = 0;
	fmt->str = NULL;
	fmt->tmp = NULL;
	fmt->sign = FALSE;
	fmt->len = 0;
	fmt->str_len = 0;
}

void	ft_get_size(char *flag, int *flag_size, char **format)
{
	*flag = TRUE;
	++(*format);
	*flag_size = ft_skip_atoi(format);
	--(*format);
}

int	ft_parser_flag(va_list ap, char **format)
{
	t_flag		flag;
	t_format	fmt;

	ft_init(&flag, &fmt);
	while (ft_strchr(FLAGS, **format) || ft_isdigit(**format))
	{
		if (**format == LEFT)
			ft_get_size(&flag.left, &flag.width, format);
		else if (ft_isdigit(**format))
		{
			if (**format == PAD)
				flag.pad = TRUE;
			flag.width = ft_skip_atoi(format);
			--(*format);
		}
		else if (**format == PRECISION)
			ft_get_size(&flag.precision, &flag.size, format);
		else if (**format == ALTERNATE)
			flag.alternate = TRUE;
		else if (**format == SPACE)
			flag.space = TRUE;
		else if (**format == PLUS)
			flag.plus = TRUE;
		++(*format);
	}
	return (ft_parser_type(ap, **format, &flag, &fmt));
}
