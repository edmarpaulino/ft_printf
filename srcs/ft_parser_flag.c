/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 16:02:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init(t_format *fmt)
{
	fmt->str = NULL;
	fmt->tmp = NULL;
	fmt->sign = FALSE;
	fmt->left = FALSE;
	fmt->pad = FALSE;
	fmt->precision = FALSE;
	fmt->alternate = FALSE;
	fmt->space = FALSE;
	fmt->plus = FALSE;
	fmt->width = 0;
	fmt->size = 0;
	fmt->len = 0;
	fmt->str_len = 0;
}

int	ft_check_flag(char *flags, int c)
{
	while (*flags && *flags != c)
		++flags;
	return (*flags == c);
}

void	ft_get_size(char *fmt, int *flag_size, char **format)
{
	*fmt = TRUE;
	++(*format);
	*flag_size = ft_skip_atoi(format);
	--(*format);
}

int	ft_parser_flag(va_list ap, char **format)
{
	t_format	fmt;

	ft_init(&fmt);
	while (ft_check_flag(FLAGS, **format) || ft_isdigit(**format))
	{
		if (**format == LEFT)
			ft_get_size(&fmt.left, &fmt.width, format);
		else if (ft_isdigit(**format))
		{
			if (**format == PAD)
				fmt.pad = TRUE;
			fmt.width = ft_skip_atoi(format);
			--(*format);
		}
		else if (**format == PRECISION)
			ft_get_size(&fmt.precision, &fmt.size, format);
		else if (**format == ALTERNATE)
			fmt.alternate = TRUE;
		else if (**format == SPACE)
			fmt.space = TRUE;
		else if (**format == PLUS)
			fmt.plus = TRUE;
		++(*format);
	}
	return (ft_parser_type(ap, **format, &fmt));
}
