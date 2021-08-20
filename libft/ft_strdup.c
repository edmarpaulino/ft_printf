/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:54:32 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 15:05:35 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char	*str)
{
	size_t	len;
	char	*dup;

	len = (ft_strlen((char *)str) + 1);
	dup = (char *)malloc(len * sizeof(*str));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len);
	return (dup);
}
