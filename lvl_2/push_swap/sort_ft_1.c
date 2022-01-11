/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:07:58 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 12:17:52 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *lst)
{
	t_stack	*p;

	p = lst;
	while (p->next)
	{
		if (p->value > p->next->value)
			return (0);
		p = p->next;
	}
	return (1);
}

int	*ft_copy_tab(t_stack **lst)
{
	int		*t;
	t_stack	*p;
	int		i;

	i = 0;
	t = malloc(ft_lstcount(lst[0]) * sizeof(int));
	if (!t)
		return (NULL);
	p = lst[0];
	while (p)
	{
		t[i] = p->value;
		i++;
		p = p->next;
	}
	return (t);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = -1;
	c = size;
	while (--size)
	{
		i = -1;
		while (++i < c - 1)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
		}
	}
}
