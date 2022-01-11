/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:49:41 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 15:18:17 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_while(t_stack **p, int size)
{
	int	i;

	i = 0;
	while (p[0])
	{
		if (!p[0]->keep && p[0]->index < size)
			break ;
		i++;
		p[0] = p[0]->next;
	}
	return (i);
}

t_stack	*ft_check_push(t_stack **a, int size)
{
	t_stack	*p;
	t_stack	*l;
	int		i;
	int		j;

	p = a[0];
	l = ft_lstlast(a[0]);
	i = 0;
	j = 1;
	i = ft_while(&p, size);
	while (l)
	{
		if (!l->keep && l->index < size)
			break ;
		j++;
		l = l->prev;
	}
	if (i <= j)
		return (p);
	return (l);
}

int	ft_swap_test(t_stack **a, t_utils *util)
{
	int	ret;

	ft_f_swap(a);
	ret = ft_big_loop(a[0], 0);
	ft_f_swap(a);
	if (ret > util->big_loop)
		return (1);
	return (0);
}

int	ft_cont_inst(t_stack **a, t_stack *p)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a[0];
	while (tmp)
	{
		if (tmp->value == p->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i <= ft_lstcount(a[0]) / 2)
		return (i);
	return (i - ft_lstcount(a[0]));
}

void	ft_doub_rot(t_stack **a, t_stack **b, int *rot_a, int *rot_b)
{
	while (*rot_a > 0 && *rot_b > 0)
	{
		(*rot_b)--;
		(*rot_a)--;
		ft_rr(a, b, 1);
	}
	while (*rot_a < 0 && *rot_b < 0)
	{
		(*rot_b)++;
		(*rot_a)++;
		ft_rrr(a, b, 1);
	}
}
