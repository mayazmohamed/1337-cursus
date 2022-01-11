/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:24:39 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/27 21:26:57 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_general *gen, t_ident *ident)
{
	gen->posit++;
	while (ft_strchr(FLAGS, gen->input[gen->posit]) && gen->input[gen->posit])
	{
		if (gen->input[gen->posit] == '-')
			ident->flags *= F_MINUS;
		else if (gen->input[gen->posit] == '+')
			ident->flags *= F_PLUS;
		else if (gen->input[gen->posit] == '0')
			ident->flags *= F_ZERO;
		else if (gen->input[gen->posit] == ' ')
			ident->flags *= F_SPACE;
		else if (gen->input[gen->posit] == '#')
			ident->flags *= F_HASH;
		gen->posit++;
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	nbr;
	int	signal;
	int	aux;

	nbr = 0;
	aux = 0;
	signal = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 - (*str++ - 48);
		if (aux < nbr)
		{
			if (signal < 0)
				return (-1);
			else
				return (0);
		}
		aux = nbr;
	}
	return (nbr * signal);
}

int	get_sizes(t_general *gen, t_ident *ident)
{
	int	size;

	size = 0;
	if (gen->input[gen->posit] == '*')
	{
		size = va_arg(gen->argument, int);
		gen->posit++;
		if (size < 0 && gen->input[gen->posit - 2] != '.')
		{
			ident->flags *= F_MINUS;
			size *= -1;
		}
	}
	else if (gen->input[gen->posit])
	{
		size = ft_atoi(&gen->input[gen->posit]);
		while (ft_strchr(DIGITS, gen->input[gen->posit])
			&& gen->input[gen->posit])
			gen->posit++;
	}
	return (size);
}
