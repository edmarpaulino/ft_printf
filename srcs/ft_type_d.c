/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:06:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_d(int	d)
{
	int		len;
	char	*str;

	len = 0;
	if (d < 0)
		str = ft_uitoa(-(long)d);
	else
		str = ft_uitoa(d);
	if (!str)
		return (0);
	if (d < 0)
		len = write(1, "-", 1);
	len += write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
