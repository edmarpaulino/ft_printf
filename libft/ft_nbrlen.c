/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:22:07 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/31 10:26:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(size_t nbr, size_t base)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= base;
		++len;
	}
	return (len);
}
