/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 20:00:49 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//	CAPTURE THE FLAG

void	ft_init_flags(t_flag	*flag) // not prototyped
{
	flag->left = FALSE;
	flag->pad = FALSE;
	flag->pad_size = 0;
	flag->precision = FALSE;
	flag->precision_size = 0;
	flag->alter = FALSE;
	flag->space = FALSE;
	flag->plus = FALSE;
}

/*
	ft_check_flag
	check if the condition is valid, if is not then returns error
	if  ft_check_flag returns erro the fmt return to the initial
	fmt position minus 1 (% position = start) and returns error too.
*/

int	ft_check_flag(char	current, t_flag	flag) // not prototyped
{
	return (ERROR);
}

int	ft_parser_flag(va_list	ap, char	**fmt) // not prototyped
{
	t_flag	flag;
	char	*start;

	start = (*fmt - 1);
	ft_init_flags(&flag);
	while (ft_strchr(FLAGS, **fmt) || ft_strchr(DIGITS, **fmt))
	{
		if (**fmt == LEFT)
			flag.left = TRUE;
		else if (**fmt == PAD)
			flag.pad = TRUE;
		else if (**fmt == PRECISION)
			flag.precision = TRUE;
		else if (**fmt == ALTERNATE)
			flag.alter = TRUE;
		else if (**fmt == SPACE)
			flag.space = TRUE;
		else if (**fmt == PLUS)
			flag.plus = TRUE;
		++(*fmt);
	}
}