/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:48:36 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/09 11:06:07 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	int		i;
	char	*ptr;

	ptr = (char *)big;
	if (!*little)
		return (ptr);
	while (*ptr && len)
	{
		if (*ptr == *little)
		{
			i = 1;
			while (little[i] && ptr[i] == little[i] && len >= ft_strlen(little))
				i++;
			if (!little[i])
				return (ptr);
		}
		ptr++;
		len--;
	}
	return (0);
}
