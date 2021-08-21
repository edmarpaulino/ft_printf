/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:49:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/21 13:24:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MIN
#  define INT_MIN -2147483648 
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif

size_t	ft_strlen(char	*str);
size_t	ft_strnlen(char	*str, size_t	n);
void	ft_putchar(int	c);
void	ft_putstr(char	*str);
int		ft_nbrlen(size_t	n, size_t	base);
char	*ft_itoa(int	n);
char	*ft_uitoa(unsigned int	un);
char	*ft_strdup(const char	*str);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t dest_len);
char	*ft_hex_address(size_t	addr, char	*base);
char	*ft_convert_base(size_t	nbr, char	*base);

#endif
