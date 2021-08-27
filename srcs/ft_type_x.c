/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:35:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 15:09:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_x(unsigned int	x, char	*base, t_flag	*flag)
{
	int		len;
	char	*hex;

	hex = ft_convert_base(x, base);
	if (!hex || !flag)
		return (ERROR);
	len = write(1, hex, ft_strlen(hex));
	free(hex);
	return (len);
}
