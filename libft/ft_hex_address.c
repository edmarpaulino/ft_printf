/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:55:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 17:28:52 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_hex_address(size_t	addr, char	*base)
{
	char	*hex_addr;
	int		i;

	hex_addr = (char *)malloc(13 * sizeof(*base));
	if (!hex_addr)
		return (NULL);
	i = 12;
	hex_addr[12] = '\0';
	while (i-- > 0)
	{
		hex_addr[i] = base[addr % 16];
		addr /= 16;
	}
	return (hex_addr);
}
