/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:23:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/21 13:23:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert(int	n, char	*str)
{
	int	len;

	if (n < 0)
	{
		n = -n;
		len = (ft_nbrlen(n, 10) + 2);
		str = (char *)malloc(len * sizeof(*str));
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		len = (ft_nbrlen(n, 10) + 1);
		str = (char *)malloc(len * sizeof(*str));
		if (!str)
			return (NULL);
	}
	str[--len] = '\0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int	n)
{
	char	*str;

	str = 0;
	if (n < INT_MIN || n > INT_MAX)
		return (NULL);
	if (n == INT_MIN)
		str = ft_strdup("-2147483648");
	else if (n == 0)
		str = ft_strdup("0");
	else
		str = ft_convert(n, str);
	return (str);
}
