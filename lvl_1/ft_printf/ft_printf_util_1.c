/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:21:43 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/27 21:29:27 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int	ft_print_space(int cont, t_ident ident)
{
	int		i;
	char	c;

	i = -1;
	if (ident.flags % F_ZERO == 0 && ident.flags % F_MINUS != 0)
		c = '0';
	else
		c = ' ';
	while (++i < cont)
		ft_putchar_fd(c, 1);
	if (cont > 0)
		return (cont);
	else
		return (0);
}

char	*ft_prefix(long long *n, t_ident ident)
{
	if ((ident.conversion == 'x' && (ident.flags % F_HASH == 0 && *n != 0))
		|| ident.conversion == 'p')
		return (ft_strdup("0x"));
	else if (ident.conversion == 'X' && (ident.flags % F_HASH == 0 && *n != 0))
		return (ft_strdup("0X"));
	else if (ident.conversion == 'x' || ident.conversion == 'X')
		return (NULL);
	else if (*n < 0)
	{
		*n *= -1;
		return (ft_strdup("-"));
	}
	else if (ident.flags % F_PLUS == 0)
		return (ft_strdup("+"));
	else if (ident.flags % F_SPACE == 0)
		return (ft_strdup(" "));
	return (NULL);
}

size_t	ft_intsize(size_t n, size_t size, size_t n_base)
{
	if (n < n_base)
		return (size + 1);
	return (ft_intsize(n / n_base, size + 1, n_base));
}

char	*ft_itoa_base_u(size_t n, char const *base)
{
	char		*nbr;
	size_t		size;
	size_t		n_base;

	n_base = ft_strlen(base);
	size = ft_intsize(n, 0, n_base);
	nbr = malloc(size + 1 * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[size--] = '\0';
	while (n >= n_base)
	{
		nbr[size--] = base[n % n_base];
		n /= n_base;
	}
	nbr[size] = base[n % n_base];
	return (nbr);
}
