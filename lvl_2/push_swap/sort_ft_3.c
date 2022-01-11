/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:09:46 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/21 15:11:47 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_head(t_stack *a, t_stack *p, int set)
{
	t_stack	*head;
	int		j;
	int		i;

	j = 0;
	i = -1;
	head = p;
	while (head)
	{
		if (set)
			head->keep = 0;
		if (i < head->index)
		{
			i = head->index;
			j++;
			if (set)
				head->keep = 1;
		}
		head = head->next;
		if (!head)
			head = a;
		if (head == p)
			break ;
	}
	return (j);
}

int	ft_big_loop(t_stack *a, int set)
{
	int		i;
	int		head;
	t_stack	*rest;
	t_stack	*p;

	i = 0;
	p = a;
	while (p)
	{
		head = ft_get_head(a, p, 0);
		if (head > i)
		{
			i = head;
			rest = p;
		}
		p = p->next;
	}
	if (set)
		ft_get_head(a, rest, 1);
	return (i);
}

void	ft_in_util(t_utils *p, t_stack *a)
{
	p->dist = 1000;
	p->max_size = ft_lstcount(a);
	p->lst_size = p->max_size;
	if (p->max_size / 150 > 1)
		p->groups = p->max_size / 150;
	else
		p->groups = 1;
	p->group_size = p->max_size / p->groups;
	p->big_loop = ft_big_loop(a, 1);
}
