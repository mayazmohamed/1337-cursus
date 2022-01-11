/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:14:56 by momayaz           #+#    #+#             */
/*   Updated: 2021/12/23 13:30:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_input_type(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]) || (args[i][j] == '-' && (j != 0
				|| !ft_isdigit(args[i][j + 1]))))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_double(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (!ft_strcmp(args[i], args[j]))
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

t_stack	*ft_fill_stack(char **args)
{
	t_stack	*tmp;
	t_stack	*list;
	int		i;

	list = NULL;
	i = 0;
	while (args[i])
	{
		tmp = ft_new_node(ft_atoi(args[i]));
		if (!tmp)
		{
			free_list(list);
			return (NULL);
		}
		ft_lstadd_back(&list, tmp);
		i++;
	}
	return (list);
}

t_stack	*ft_devide_args(char **args)
{
	ft_check_input_type(args);
	ft_check_double(args);
	return (ft_fill_stack(args));
}

int	ft_check_sort_asc(t_stack *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
