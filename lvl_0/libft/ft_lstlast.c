/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:18:13 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/08 20:18:36 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cp;

	if (!(lst))
		return (lst);
	cp = lst;
	while (cp->next)
		cp = cp->next;
	return (cp);
}
