/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:15:38 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/09 10:49:01 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	int		i;
	char	*t;
	char	*src;

	src = (char *) s;
	i = ft_strlen(src);
	t = malloc((i + 1) * sizeof(char));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		t[i] = src[i];
		i++;
	}
	t[i] = 0;
	return (t);
}
