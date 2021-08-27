/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:18:06 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/27 15:16:32 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_u(unsigned int	u, t_flag	*flag)
{
	int		len;
	char	*str;

	if (!flag)
		return (ERROR);
	str = ft_uitoa(u);
	if (!str)
		return (ERROR);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
