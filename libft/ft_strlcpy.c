/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:57:58 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 15:06:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t	dest_len)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen((char *)src);
	if (dest_len)
	{
		while (--dest_len && *src)
			*(dest++) = *(src++);
		*dest = '\0';
	}
	return (src_len);
}
