/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:21:35 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/28 15:56:05 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_limits(t_general *gen, t_ident *ident)
{
	ident->width = get_sizes(gen, ident);
	if (gen->input[gen->posit] == '.')
	{
		gen->posit++;
		ident->precision = get_sizes(gen, ident);
	}
}

void	get_conversion(t_general *gen, t_ident *ident)
{
	if (ft_strchr(CONVERSION, gen->input[gen->posit]) && gen->input[gen->posit])
	{
		ident->conversion = gen->input[gen->posit];
		gen->posit++;
		if (ident->conversion == 'c')
			ft_prepare_c(gen, *ident);
		else if (ident->conversion == 's')
			ft_prepare_s(gen, *ident);
		else if (ident->conversion == 'p')
			ft_prepare_p(gen, *ident);
		else if (ident->conversion == '%')
			ft_prepare_pct(gen, *ident);
		else
			ft_prepare_nbr(gen, *ident);
	}
}

void	ft_init_ident(t_ident *identifier)
{
	identifier->flags = 1;
	identifier->width = -1;
	identifier->precision = -1;
	identifier->conversion = 0;
}

void	ft_print_ident(t_general *gen, t_ident *ident)
{
	ft_init_ident(ident);
	get_flags(gen, ident);
	get_limits(gen, ident);
	get_conversion(gen, ident);
}

int	ft_printf(const char *format, ...)
{
	t_general	gen;
	t_ident		ident;

	gen.posit = 0;
	gen.size = 0;
	gen.input = ft_strdup(format);
	va_start(gen.argument, format);
	while (gen.input[gen.posit])
	{
		if (format[gen.posit] == '%')
			ft_print_ident(&gen, &ident);
		else
		{
			ft_putchar_fd(gen.input[gen.posit], 1);
			gen.posit++;
			gen.size++;
		}
	}
	va_end(gen.argument);
	ft_strfree(&gen.input);
	return (gen.size);
}
