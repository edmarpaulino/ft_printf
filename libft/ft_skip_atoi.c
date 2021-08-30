/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:41:43 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:00:38 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_skip_atoi(char **str)
{
	int	n;

	n = 0;
	while (ft_isdigit(**str))
	{
		n = (n * 10) + (**str - '0');
		++(*str);
	}
	return (n);
}
