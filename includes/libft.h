/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:49:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/25 19:30:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define TRUE	1
# define FALSE	0
# define ERROR	-1

size_t	ft_strlen(char	*str);
int		ft_nbrlen(size_t	nbr, size_t	base);
char	*ft_uitoa(unsigned int	un);
char	*ft_convert_base(size_t	nbr, char	*base);

#endif
