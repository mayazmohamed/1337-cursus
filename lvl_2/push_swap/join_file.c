/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:30:41 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 13:23:58 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_concta(char *dest, char *src)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lenght;
	int		i;
	char	*concat;

	if (size > 0)
		lenght = ft_strlen(sep) * (size - 1);
	i = 1;
	while (i < size)
	{
		lenght += ft_strlen(strs[i]);
		i++;
	}
	concat = malloc(sizeof(char) * (lenght + 1));
	if (!concat)
		return (NULL);
	i = 1;
	*concat = 0;
	while (i < size)
	{
		ft_concta(concat, strs[i]);
		if (i < size - 1)
			ft_concta(concat, sep);
		i++;
	}
	return (concat);
}
