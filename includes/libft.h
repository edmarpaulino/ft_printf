/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:49:40 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/29 15:27:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define DIGITS	"0123456789"
# define TRUE	1
# define FALSE	0
# define ERROR	-1

int		ft_isdigit(int c);
int		ft_skip_atoi(char **str);
int		ft_nbrlen(size_t nbr, size_t base);
int		ft_putnchar(int c, int n);
char	*ft_uitoa(unsigned int un);
char	*ft_convert_base(size_t nbr, char *base);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
