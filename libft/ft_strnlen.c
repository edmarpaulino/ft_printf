/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 19:46:47 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/19 20:42:21 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strnlen(char	*str, size_t	n)
{
	size_t	len;

	len = 0;
	if (!str || !n)
		return (len);
	while (str[len] && len < n)
		++len;
	return (len);
}
