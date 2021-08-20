/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:43:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/20 18:36:55 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_convert_base(size_t	nbr, char	*base)
{
	int		base_len;
	int		size;
	char	*convert;

	if (nbr == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base);
	size = ft_unbrlen(nbr, base_len);
	convert = (char *)malloc((size + 1) * sizeof(*base));
	if (!convert)
		return (NULL);
	convert[size] = '\0';
	while (size--)
	{
		convert[size] = base[nbr % (size_t)base_len];
		nbr /= (size_t)base_len;
	}
	return (convert);
}
