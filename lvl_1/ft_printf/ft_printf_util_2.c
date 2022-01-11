/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:22:31 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/27 21:29:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sufix(long long n, t_ident ident)
{
	char	*nbr;

	if (n == 0 && ident.precision >= 0)
		nbr = ft_strdup("");
	else if (ident.conversion == 'p')
		nbr = ft_itoa_base_u(n, B_HEX_L);
	else if (ident.conversion == 'd' || ident.conversion == 'i'
		|| ident.conversion == 'u')
		nbr = ft_itoa_base_u(n, B_DEC);
	else if (ident.conversion == 'x')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_L);
	else if (ident.conversion == 'X')
		nbr = ft_itoa_base_u((unsigned int)n, B_HEX_U);
	else
		nbr = NULL;
	return (nbr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*str;
	unsigned long int	i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*str = (unsigned char)c;
		i++;
		str++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (!src)
		return (0);
	len = 0;
	while (len + 1 < dstsize && *(src + len))
	{
		*(dst + len) = *(src + len);
		len++;
	}
	if (dstsize != 0)
		*(dst + len) = '\0';
	while (*(src + len))
		len++;
	return (len);
}
