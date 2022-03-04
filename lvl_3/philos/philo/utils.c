/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:21:18 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 14:56:06 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	rst;

	i = 0;
	sign = 1;
	rst = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\t' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rst = rst * 10 + str[i] - '0';
		i++;
	}
	return (sign * rst);
}

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				printf("argiment %s : is not a digit", args[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_philo	*ft_fill_stack(char *av, t_util *util)
{
	t_philo	*tmp;
	t_philo	*list;
	int		i;

	list = NULL;
	i = 1;
	while (i < ft_atoi(av) + 1)
	{
		tmp = ft_new_node(i, util);
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

t_philo	*ft_devide_args(char **args, t_util *util)
{
	if (!check_args(args))
		return (NULL);
	return (ft_fill_stack(args[1], util));
}
