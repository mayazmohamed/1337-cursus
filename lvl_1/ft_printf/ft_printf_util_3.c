/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:23:07 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/27 21:28:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill_zeros(char *pref, char *suf, int len_beg, int len_end)
{
	char	*str;
	int		pref_size;

	pref_size = ft_strlen(pref);
	str = (char *)ft_calloc(len_end + pref_size + 1, sizeof(char));
	ft_memset(str, '0', len_end + pref_size);
	if (pref_size > 0)
	{
		ft_strlcpy(&str[0], pref, pref_size + 1);
		str[pref_size] = '0';
	}
	ft_strlcpy(&str[len_end - len_beg + pref_size], suf, len_beg + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (const char)c)
			return ((char *)s);
		s++;
	}
	if ((const char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_get_nbr(long long n, t_ident *ident)
{
	char	*prefix;
	char	*sufix;
	char	*nbr;
	int		nbr_len;

	prefix = ft_prefix(&n, *ident);
	sufix = ft_sufix(n, *ident);
	nbr_len = ft_strlen(sufix);
	if ((n == 0 && ident->precision == 0) || ident->precision >= nbr_len)
		nbr = ft_fill_zeros(prefix, sufix, nbr_len, ident->precision);
	else
	{
		nbr_len += ft_strlen(prefix);
		if (ident->width > nbr_len && ident->flags % F_ZERO == 0
			&& ident->flags % F_MINUS != 0 && ident->precision < 0)
			nbr = ft_fill_zeros(prefix, sufix, nbr_len, ident->width);
		else
			nbr = ft_fill_zeros(prefix, sufix, nbr_len, nbr_len);
	}
	while (ident->flags % F_ZERO == 0)
		ident->flags /= F_ZERO;
	ft_strfree(&prefix);
	ft_strfree(&sufix);
	return (nbr);
}

void	print_0(int str_len)
{
	ft_putchar_fd('\0', 1);
	str_len = 1;
}

void	ft_print_all(t_general *gen, t_ident ident, char *pre)
{
	int	cont;
	int	str_len;
	int	i;

	i = -1;
	str_len = ft_strlen(pre);
	if (pre[0] == 0 && pre[1] == 0 && ident.conversion == 'c')
		str_len++;
	if (ident.conversion == 'c')
		cont = ident.width - 1;
	else
		cont = ident.width - str_len;
	if (ident.flags % F_MINUS != 0 && ident.width > 0)
		gen->size += ft_print_space(cont, ident);
	while (++i < str_len)
	{
		if (ident.conversion == 'c' && str_len == 2)
			print_0(str_len);
		else
			ft_putchar_fd(*(pre + i), 1);
	}
	gen->size += str_len;
	if (ident.flags % F_MINUS == 0 && ident.width > 0)
		gen->size += ft_print_space(cont, ident);
}
