/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ft_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:13:59 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 15:19:00 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack **a, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(a[0]) < 2)
		return ;
	tmp1 = a[0];
	tmp2 = a[0]->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = ft_lstlast(a[0]);
	ft_lstlast(a[0])->next = tmp1;
	tmp1->next = NULL;
	a[0] = tmp2;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(b[0]) < 2)
		return ;
	tmp1 = b[0];
	tmp2 = b[0]->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = ft_lstlast(b[0]);
	ft_lstlast(b[0])->next = tmp1;
	tmp1->next = NULL;
	b[0] = tmp2;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rev_rot_a(t_stack **a, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(a[0]) < 2)
		return ;
	tmp1 = ft_lstlast(a[0]);
	tmp2 = a[0];
	tmp1->prev->next = NULL;
	tmp1->prev = tmp2->prev;
	tmp2->prev = tmp1;
	tmp1->next = tmp2;
	a[0] = tmp1;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rev_rot_b(t_stack **b, int print)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (ft_lstcount(b[0]) < 2)
		return ;
	tmp1 = ft_lstlast(b[0]);
	tmp2 = b[0];
	tmp1->prev->next = NULL;
	tmp1->prev = tmp2->prev;
	tmp2->prev = tmp1;
	tmp1->next = tmp2;
	b[0] = tmp1;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rr(t_stack **a, t_stack **b, int i)
{
	ft_rotate_a(a, 0);
	ft_rotate_b(b, 0);
	if (i)
		write(1, "rr\n", 3);
}
