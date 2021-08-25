/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:28:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 20:00:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strchr(char	*str, char	c) // not prototyped
{
	while (*str)
	{
		if (*str == c)
			return (TRUE);
		++str;
	}
	return (FALSE);
}