/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:22:07 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 17:47:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_nbrlen(ssize_t	n, int	base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= (ssize_t)base;
		++len;
	}
	return (len);
}
