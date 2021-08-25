/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:43:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 18:29:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_convert_base(size_t	nbr, char	*base)
{
	int		base_len;
	int		len;
	char	*converted;

	base_len = ft_strlen(base);
	len = ft_nbrlen(nbr, base_len);
	converted = (char *)malloc((len + 1) * sizeof(*base));
	if (!converted)
		return (NULL);
	converted[len] = '\0';
	while (len--)
	{
		converted[len] = base[nbr % (size_t)base_len];
		nbr /= (size_t)base_len;
	}
	return (converted);
}
