/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:04:08 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/26 16:04:10 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_options(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_skip_quote(str, &i) == -1)
			return (1);
		if (ft_strchr(TABLE, str[i]) != -1 && str[i + 1] == ' ')
		{
			i++;
			while (str[i] && str[i] == ' ')
				i++;
			if (ft_strchr(TABLE, str[i]) != -1)
			{
				printf ("MiniShell: syntax error near ");
				printf("unexpected token `%c'\n", str[i]);
				return (1);
			}
		}
		else
			i++;
	}
	return (0);
}

int	ft_valid_options_mini(char c, char get, int *cp)
{
	if (ft_strchr(TABLE, c) != -1)
	{
		if (get != c)
		{
			printf ("MiniShell: syntax error near unexpected token `%c'\n", c);
			return (1);
		}
		if (get == c)
		{
			(*cp)++;
			if (*cp == 2)
			{
				printf ("MiniShell: syntax error near ");
				printf("unexpected token `%c'\n", c);
				return (1);
			}
		}
	}
	if (get == '&' && *cp == 0)
	{
		printf ("MiniShell: syntax error near unexpected token `&'\n");
		return (1);
	}
	return (0);
}

int	ft_valid_options(char *str)
{
	int		i;
	int		cp;
	char	get;

	i = 0;
	cp = 0;
	while (str[i])
	{
		if (ft_skip_quote(str, &i) == -1)
			return (1);
		if (ft_strchr(TABLE, str[i]) != -1)
		{
			get = str[i++];
			if (ft_valid_options_mini(str[i], get, &cp))
				return (1);
		}
		else
		{
			cp = 0;
			i++;
		}
	}
	return (0);
}

int	ft_check_syntax(char *str)
{
	if (ft_check_options(str))
		return (1);
	if (ft_valid_options(str))
		return (1);
	if (ft_valid_parenthesis(str))
		return (1);
	return (0);
}
