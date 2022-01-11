/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:52:52 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 15:17:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotat(t_stack **a, t_stack **b, int rot_a, int rot_b)
{
	ft_doub_rot(a, b, &rot_a, &rot_b);
	while (rot_a > 0)
	{
		rot_a--;
		ft_rotate_a(a, 1);
	}
	while (rot_a < 0)
	{
		rot_a++;
		ft_rev_rot_a(a, 1);
	}
	while (rot_b > 0)
	{
		rot_b--;
		ft_rotate_b(b, 1);
	}
	while (rot_b < 0)
	{
		rot_b++;
		ft_rev_rot_b(b, 1);
	}
}

void	ft_firts_step(t_stack **a, t_stack **b, int group, t_utils *p)
{
	t_stack	*tmp;
	int		pos;

	while (ft_lstcount(a[0]) >= p->big_loop && group <= p->groups + 1)
	{
		tmp = ft_check_push(a, (group * p->group_size));
		if (!tmp && ++group)
			continue ;
		pos = ft_cont_inst(a, tmp);
		if (a[0] && ft_swap_test(a, p))
		{
			ft_swap_a(a, 1);
			p->big_loop = ft_big_loop(a[0], 1);
		}
		else if (a[0] && !tmp->keep && !pos)
		{
			ft_push_b(a, b, 1);
			p->lst_size--;
		}
		else if (p->groups == 1)
			ft_rr(a, b, 1);
		else
			ft_do_rotat(a, b, ft_get_min(1, ft_get_max(-1, pos)), 0);
	}
}
