/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:34:10 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/12 10:21:40 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*nptr;
	size_t		i;

	i = -1;
	nptr = malloc(nmemb * size);
	if (!nptr)
		return (NULL);
	ft_bzero(nptr, nmemb * size);
	return (nptr);
}
