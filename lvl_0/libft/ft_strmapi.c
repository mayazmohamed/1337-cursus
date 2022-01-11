/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:26:13 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/09 11:05:17 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;

	i = 0;
	if (!s || (!s &&!f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	t = ft_strdup(s);
	if (!t)
		return (t = NULL);
	while (t[i])
	{
		t[i] = (*f)(i, t[i]);
		i++;
	}
	return (t);
}
