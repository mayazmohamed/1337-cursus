/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:08:15 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 12:19:28 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_index_lst(t_stack **a)
{
	int		*t;
	int		i;
	int		j;
	t_stack	*p;

	i = 0;
	j = 0;
	p = a[0];
	t = ft_copy_tab(a);
	ft_sort_int_tab(t, ft_lstcount(a[0]));
	while (p)
	{
		i = 0;
		while (i < ft_lstcount(a[0]))
		{
			if (p->value == t[i])
				p->index = i;
			i++;
		}
		p = p->next;
	}
	free(t);
}
