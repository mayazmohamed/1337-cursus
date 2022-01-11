/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:14:31 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/31 13:50:19 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort_des(t_stack *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->value < lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_rrr(t_stack **a, t_stack **b, int i)
{
	ft_rev_rot_a(a, 0);
	ft_rev_rot_b(b, 0);
	if (i)
		write(1, "rrr\n", 4);
}

void	ft_ss(t_stack **a, t_stack **b, int i)
{
	ft_swap_a(a, i);
	ft_swap_b(b, i);
	if (i)
		write(1, "ss\n", 3);
}

void	max_val(long rst)
{
	if (rst > 2147483647)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
