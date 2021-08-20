/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:22:07 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 18:37:37 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unbrlen(size_t	n, int	base)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= (size_t)base;
		++len;
	}
	return (len);
}
