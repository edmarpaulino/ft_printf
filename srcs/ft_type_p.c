/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:15:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 15:52:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_p(size_t	p, t_flag	*flag)
{
	int		len;
	char	*addr;

	len = 0;
	addr = ft_convert_base(p, LOWER_HEX);
	if (!addr)
		return (FALSE);
	if (flag->left == TRUE)
	{
		len = ft_print_alter(addr, LOWER_HEX);
		len += ft_putnchar(SPACE, (--flag->left_size - ft_strlen(addr)));
		free(addr);
		return (len);
	}
	if (flag->pad_size > 0)
		len = ft_putnchar(SPACE, (--flag->pad_size - ft_strlen(addr)));
	else if (flag->plus == TRUE)
		len = write(1, "+", 1);
	else if (flag->space == TRUE)
		len = write(1, " ", 1);
	len += ft_print_alter(addr, LOWER_HEX);
	free(addr);
	return (len);
}
