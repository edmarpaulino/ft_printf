/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:55:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 17:59:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_hex_address(size_t	addr, char	*base)
{
	char	*hex_addr;
	int		len;

	len = ft_nbrlen(addr, ft_strlen(base));
	hex_addr = (char *)malloc((len + 1) * sizeof(*base));
	if (!hex_addr)
		return (NULL);
	hex_addr[len] = '\0';
	while (len-- >= 0)
	{
		hex_addr[len] = base[addr % 16];
		addr /= 16;
	}
	return (hex_addr);
}
