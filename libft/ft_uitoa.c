/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:23:19 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/31 10:30:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_uitoa(unsigned int un)
{
	char	*str;
	int		len;

	len = ft_nbrlen(un, 10);
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (un % 10) + '0';
		un /= 10;
	}
	return (str);
}
