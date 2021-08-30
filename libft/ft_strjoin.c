/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:43:47 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:21:29 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	new = (char *)malloc((s1_len + s2_len + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, (s1_len + 1));
	ft_strlcpy((new + s1_len), s2, (s2_len + 1));
	return (new);
}
