/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:38 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 15:32:41 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char *av[])
{
	t_all	all;

	if (ac < 5 || ac > 6)
		exit(ft_putstr("Error : Wrong Number Of Arguments!!\n", 1));
	if (ft_parse_args(&all, av))
		exit(ft_putstr("Error : Wrong Arguments Format!!\n", 1));
	ft_exec(&all);
	return (0);
}
