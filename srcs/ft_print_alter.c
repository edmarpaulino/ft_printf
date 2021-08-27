/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:21:10 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 09:54:44 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_alter(char	*hex, char	*base)
{
	int	len;

	if (!ft_strcmp(base, LOWER_HEX))
		len = write(1, "0x", 2);
	else
		len = write(1, "0X", 2);
	len += write(1, hex, ft_strlen(hex));
	return (len);
}
