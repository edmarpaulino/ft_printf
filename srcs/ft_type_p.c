/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:15:03 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 17:37:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_p(size_t	p)
{
	int		len;
	char	*addr;

	addr = ft_convert_base(p, LOWER_HEX);
	if (!addr)
		return (0);
	len = write(1, "0x", 2);
	len += write(1, addr, ft_strlen(addr));
	free(addr);
	return (len);
}
