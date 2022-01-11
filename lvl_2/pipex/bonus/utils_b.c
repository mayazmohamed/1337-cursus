/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:00:08 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:00:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if ((char) c == 0)
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*sp;

	i = 0;
	sp = (char *)s;
	while (i < n)
		sp[i++] = 0;
}

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
