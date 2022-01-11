/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:25 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/08 20:09:02 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	calcul_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_tab(char *t, unsigned int nb, unsigned int len)
{
	t[len--] = 0;
	while (nb > 0)
	{
		t[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char			*t;
	unsigned int	nb;
	unsigned int	len;

	if (n < 0)
	{
		nb = -n;
		len = 1;
	}
	else
	{
		nb = n;
		len = 0;
	}
	len += calcul_len(nb);
	t = malloc(len + 1 * sizeof(char));
	if (!t)
		return (NULL);
	if (nb == 0)
		t[0] = '0';
	if (n < 0)
		t[0] = '-';
	t = ft_tab(t, nb, len);
	return (t);
}
