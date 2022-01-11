/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:13:12 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/30 15:28:41 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **a, int b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(a[0]) < 2)
		return ;
	tmp1 = a[0];
	tmp2 = a[0]->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	a[0] = tmp2;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
	if (b)
		write(1, "sa\n", 3);
}

void	ft_f_swap(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(a[0]) < 2)
		return ;
	tmp1 = a[0];
	tmp2 = a[0]->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	a[0] = tmp2;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
}

void	ft_swap_b(t_stack **b, int i)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(b[0]) < 2)
		return ;
	tmp1 = b[0];
	tmp2 = b[0]->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
	b[0] = tmp2;
	if (i)
		write(1, "sb\n", 3);
}

void	ft_push_a(t_stack **b, t_stack **a, int i)
{
	t_stack	*tmp1;

	if (!b[0])
		return ;
	tmp1 = b[0]->next;
	ft_lstadd_front(a, b[0]);
	if (tmp1)
		tmp1->prev = NULL;
	b[0] = tmp1;
	if (i)
		write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp1;

	if (!a[0])
		return ;
	tmp1 = a[0]->next;
	ft_lstadd_front(b, a[0]);
	if (tmp1)
		tmp1->prev = NULL;
	a[0] = tmp1;
	if (i)
		write(1, "pb\n", 3);
}
