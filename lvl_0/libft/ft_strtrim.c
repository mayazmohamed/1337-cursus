/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:30:43 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/09 11:23:31 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_trim(char const a, char const *b)
{
	while (*b)
	{
		if (a == *b)
			return (1);
		b++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pt;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	while (*s1 && is_trim(*s1, set))
		s1++;
	if (!*s1)
	{
		pt = malloc(1 * sizeof(char));
		return (pt[0] = 0, pt);
	}
	while (s1[i])
		i++;
	while (is_trim(s1[i - 1], set))
		i--;
	pt = malloc(i + 1 * sizeof (char));
	if (!pt)
		return (NULL);
	pt[i] = 0;
	while (--i >= 0)
		pt[i] = s1[i];
	return (pt);
}
