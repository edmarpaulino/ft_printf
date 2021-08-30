/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:43:52 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:19:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_convert_base(size_t n, char *base)
{
	int		base_len;
	int		len;
	char	*n_base;

	base_len = ft_strlen(base);
	len = ft_nbrlen(n, base_len);
	n_base = (char *)malloc((len + 1) * sizeof(*base));
	if (!n_base)
		return (NULL);
	n_base[len] = '\0';
	while (len--)
	{
		n_base[len] = base[n % (size_t)base_len];
		n /= (size_t)base_len;
	}
	return (n_base);
}
