/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:39:09 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/24 10:25:16 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		group;
	char	**str;
	char	*t;

	group = 1;
	t = ft_strjoin(ac, av, " ");
	str = ft_split(t, ' ');
	a = ft_devide_args(str);
	if (ft_check_sort_asc(a))
		exit(0);
	ft_index_lst(&a);
	ft_big_sort(&a, &b, group);
	free_list(a);
	free_tab(str);
	free(t);
	return (0);
}
