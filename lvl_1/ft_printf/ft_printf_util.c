/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:20:25 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/27 21:29:41 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned long int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	i = 0;
	s1_cpy = malloc(len + 1 * sizeof(char));
	if (!s1_cpy)
		return (NULL);
	while (i < len)
	{
		*(s1_cpy + i) = *(s1 + i);
		i++;
	}
	*(s1_cpy + i) = '\0';
	return (s1_cpy);
}

void	ft_strfree(char **str)
{
	if (str == 0)
		return ;
	if (*str)
		free(*str);
	*str = 0;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + 48, fd);
}
