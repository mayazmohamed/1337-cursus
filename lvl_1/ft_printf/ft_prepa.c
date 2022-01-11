/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:16:06 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/28 12:41:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prepare_nbr(t_general *gen, t_ident ident)
{
	long			n;
	unsigned int	nb;
	char			*str;

	if (ident.conversion == 'u')
	{
		nb = va_arg(gen->argument, long long);
		str = ft_get_nbr(nb, &ident);
	}
	else
	{
		n = va_arg(gen->argument, int);
		str = ft_get_nbr(n, &ident);
	}
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void	ft_prepare_pct(t_general *gen, t_ident ident)
{
	char	pre[2];

	pre[0] = '%';
	pre[1] = '\0';
	ft_print_all(gen, ident, pre);
}

void	ft_prepare_p(t_general *gen, t_ident ident)
{
	size_t	p;
	char	*str;

	p = va_arg(gen->argument, size_t);
	str = ft_get_nbr(p, &ident);
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void	ft_prepare_s(t_general *gen, t_ident ident)
{
	char	*str;

	str = ft_strdup(va_arg(gen->argument, char *));
	if (!str)
		str = ft_strdup("(null)");
	if (ident.precision == 0 && ident.width == 0)
	{
		ft_strfree(&str);
		return ;
	}
	if (ident.precision >= 0 && ident.precision < (int)ft_strlen(str))
		str[ident.precision] = '\0';
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void	ft_prepare_c(t_general *gen, t_ident ident)
{
	int				c;
	unsigned char	pre[2];

	c = va_arg(gen->argument, int);
	pre[0] = (unsigned char)c;
	pre[1] = '\0';
	ft_print_all(gen, ident, (char *)pre);
}
