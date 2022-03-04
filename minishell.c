/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:03:01 by momayaz           #+#    #+#             */
/*   Updated: 2022/02/15 12:17:15 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_' || c == '\''
		|| c == '\"' || c == '=')
		return (1);
	return (0);
}

int	ft_strchr(const char *s, int c)
{
	int	i ;
	char get;

	i = 0;
	while (s[i])
	{
		// if (s[i] == '\'' || s[i] == '\"')
		// {
		// 	get = s[i++];
		// 	while (s[i] && s[i] != get)
		// 		i++;
		// }
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}
int skip_quote(char *str, int *i, int j)
{
	char	get;
	
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		get = str[(*i)++];
		while (str[*i] && str[(*i)] != get)
		{
			if (str[*i] == '\'' && j)
				return (printf("export: not valid in this context: %c quote", get), -1);
			(*i)++;
		}
		if (!str[(*i)])
			return (printf("export: not valid in this context: %c quote", get), -1);
	}
	if (!ft_isalnum(str[(*i)]))
		return (printf("export: |%c| not valid in this context: %s",str[(*i)], str), -1);
	return (0);
}
int chek(char *str, int *i)
{
	int cp;
	int scp;
	int dcp;

	cp = *i;
	scp = 0;
	dcp = 0;
	while (str[cp])
	{
		if (str[cp] == '\'')
			scp++;
		if (str[cp] == '\"')
			dcp++;
		cp++;
	}
	if (scp % 2 != 0 || dcp % 2 != 0)
		return (printf("export: not valid in this context:1 %s", str), -1);
	while (str[*i])
	{
		if (!ft_isalnum(str[*i]))
			return (printf("export: not valid in this context:1 %s", str), -1);
		if (str[*i] )
		(*i)++;
	}
	return (0);
}
int	check_str(char *str)
{
	int i;
	int index;

	i = 0;
	index = ft_strchr(str, '=');
	if (index)
	{
		while (str[i] && i <= index)
		{
			if (skip_quote(str, &i, 1) == -1)
				return (-1);
			i++;
		}
		while (str[i])
		{
			if (skip_quote(str, &i, 0) == -1)
				return (-1);
			i++;
		}
		return (1);
	}
	if (chek(str, &i) == -1)
		return (-1);
	return (0);
}

int main()
{
	char *str;

	while (1)
	{
		str = readline("minimini > ");
		printf("%d\n", check_str(str));
		
	}
}