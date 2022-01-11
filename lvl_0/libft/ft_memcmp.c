/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:35:24 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/08 20:33:15 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t;
	unsigned char	*t1;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	t = (unsigned char *)s1;
	t1 = (unsigned char *)s2;
	while (i < n - 1 && t[i] == t1[i])
		i++;
	return (t[i] - t1[i]);
}
