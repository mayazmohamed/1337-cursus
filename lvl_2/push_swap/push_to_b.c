/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:04:25 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/28 13:11:13 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_insert_placement(t_stack *b, int cur_index, int size)
{
	t_stack	*last;
	t_stack	*first;
	int		max_dist[3];

	last = ft_lstlast(b);
	first = b;
	max_dist[1] = 1000;
	max_dist[2] = 0;
	while (first)
	{
		if ((last->index > first->index
				&& (cur_index < first->index || cur_index > last->index))
			|| (cur_index > last->index && cur_index < first->index))
		{
			max_dist[0] = max_dist[2];
			if (max_dist[0] > size / 2)
				max_dist[0] -= size;
			if (ft_abs(max_dist[0]) < max_dist[1])
				max_dist[1] = max_dist[0];
		}
		last = first;
		first = first->next;
		max_dist[2]++;
	}
	return (max_dist[1]);
}

int	ft_dist_b(int i, int size)
{
	if (i >= size / 2)
		i -= size;
	return (i);
}

void	ft_cont_rot(t_stack **b, t_stack **a, t_utils *utils, int max_dist)
{
	t_stack	*tmp2;
	int		dist_b;
	int		i;
	int		insert;
	int		total_dist;

	tmp2 = b[0];
	i = 0;
	while (tmp2)
	{
		dist_b = ft_dist_b(i++, utils->max_size - utils->lst_size);
		insert = ft_insert_placement(a[0], tmp2->index, utils->lst_size);
		total_dist = ft_abs(insert) + ft_abs(dist_b);
		if (total_dist < max_dist)
		{
			max_dist = total_dist;
			utils->rot_a = insert;
			utils->rot_b = dist_b;
		}
		tmp2 = tmp2->next;
	}
}

void	ft_push_to_a(t_stack **a, t_stack **b, t_utils *p)
{
	while (b[0])
	{
		ft_cont_rot(b, a, p, 1000);
		ft_do_rotat(a, b, p->rot_a, p->rot_b);
		ft_push_a(b, a, 1);
		p->lst_size++;
	}
}

void	ft_big_sort(t_stack **a, t_stack **b, int group)
{
	t_utils	p;
	t_stack	*tmp;
	int		i;

	i = 0;
	ft_in_util(&p, a[0]);
	ft_firts_step(a, b, group, &p);
	ft_push_to_a(a, b, &p);
	tmp = a[0];
	while (tmp->index != 0)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < ft_lstcount(a[0]) / 2)
		while (!ft_check_sort_asc(a[0]))
			ft_rotate_a(a, 1);
	else
		while (!ft_check_sort_asc(a[0]))
			ft_rev_rot_a(a, 1);
}
