/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:34:51 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/09 13:41:18 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	p1 = (char *)dest;
	p2 = (char *)src;
	i = -1;
	if (p1 > p2)
		while (n--)
			p1[n] = p2[n];
	else
		while (++i < n)
			p1[i] = p2[i];
	return (dest);
}
