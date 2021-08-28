/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:31:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/28 11:25:39 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnchar(int c, int n)
{
	int	len;

	len = 0;
	while (n-- > 0)
		len += write(1, &c, 1);
	return (len);
}
