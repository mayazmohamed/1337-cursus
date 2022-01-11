/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:40:36 by momayaz           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:17 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cp;
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	if (!del)
		del = free;
	cp = *lst;
	while (cp)
	{
		tmp = cp->next;
		ft_lstdelone(cp, del);
		cp = tmp;
	}
	*lst = NULL;
}
