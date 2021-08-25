/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:23:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:00:19 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_uitoa(unsigned int	un)
{
	char	*str;
	int		len;

	len = (ft_nbrlen(un, 10) + 1);
	str = (char *)malloc(len * sizeof(*str));
	if (!str)
		return (NULL);
	str[--len] = '\0';
	while (--len >= 0)
	{
		str[len] = (un % 10) + '0';
		un /= 10;
	}
	return (str);
}
