/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:04:49 by momayaz           #+#    #+#             */
/*   Updated: 2022/05/24 09:57:19 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_util_struct(t_util *util, char **av)
{
	util->time_to_die = ft_atoi(av[2]);
	util->time_to_eat = ft_atoi(av[3]);
	util->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		util->number_eat = ft_atoi(av[5]);
}

int	main(int ac, char *av[])
{
	t_util	util;

	if ((ac != 6 && ac != 5))
		return (printf("wrong number of argument."), 0);
	if (av[5] && ft_atoi(av[5]) <= 0)
		printf("argument %s is invali\n", av[5]);
	fill_util_struct(&util, av);
	util.head = ft_devide_args(av, &util);
	if (!util.head)
		return (0);
	util.stop_thread = 1;
	util.first = util.head;
	loop_thread(&util);
}
