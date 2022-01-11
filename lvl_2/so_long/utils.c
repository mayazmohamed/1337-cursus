/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:39:05 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 13:17:32 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char c)
{
	while (*s1 && *s1 == c)
		s1++;
	if (*s1)
		return (1);
	return (0);
}

char	*str_dup(char *tab)
{
	int		i;
	char	*t;

	i = 0;
	while (tab[i])
		i++;
	t = malloc(i +1);
	i = -1;
	while (tab[++i])
		t[i] = tab[i];
	t[i] = 0;
	return (t);
}

char	*read_map(int fd)
{
	int		r;
	char	c;
	char	t[800000];
	int		i;

	r = 1;
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		t[i++] = c;
	}
	t[i] = 0;
	if (c == '\n' && !t[0])
	{
		printf("invalid map.");
		exit(1);
	}
	return (str_dup(t));
}

int	cont_line(char *t)
{
	int		fd;
	int		i;
	char	c;

	i = 0;
	fd = open(t, O_RDONLY);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	return (++i);
}
