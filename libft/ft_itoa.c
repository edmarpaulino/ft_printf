/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:23:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 16:39:26 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa(int	n)
{
	char	*str;
	int		len;

	len = (ft_nbrlen(n, 10) + 1);
	str = (char *)malloc(len * sizeof(*str));
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (--len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
