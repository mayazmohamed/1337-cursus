/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:22:48 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 15:22:20 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_print(t_util *all, int _id, char *str)
{
	pthread_mutex_lock(&all->writing);
	printf ("%10zu ms %3d %s\n", get_time() - all->start_time, _id, str);
	pthread_mutex_unlock(&all->writing);
}

void	*print(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	while (tmp->util->stop_thread)
	{
		if (tmp->util->number_eat > 0 && tmp->is_eat == tmp->util->number_eat)
			tmp->util->stop_thread = 0;
		pthread_mutex_lock(&tmp->fork_id);
		ft_print(tmp->util, tmp->ph_id, "has taken a fork");
		pthread_mutex_lock(&tmp->next->fork_id);
		ft_print(tmp->util, tmp->ph_id, "has taken a fork");
		ft_print(tmp->util, tmp->ph_id, "is eating");
		tmp->is_eat += 1;
		tmp->last_time_eat = get_time();
		usleep(tmp->util->time_to_eat * 1000);
		pthread_mutex_unlock(&tmp->fork_id);
		pthread_mutex_unlock(&tmp->next->fork_id);
		ft_print(tmp->util, tmp->ph_id, "is sleeping");
		usleep(tmp->util->time_to_sleep * 1000);
		ft_print(tmp->util, tmp->ph_id, "is thinking");
	}
	return (0);
}

void	is_die( t_util *util, t_philo *philo)
{
	while (philo)
	{
		if ((get_time() - util->head->last_time_eat) >= util->time_to_die + 5)
		{
			ft_print(util, philo->ph_id, "is died");
			util->stop_thread = 0;
			break ;
		}
		philo = philo->next;
	}
}

void	loop_thread(t_util *util)
{
	util->start_time = get_time();
	while (util->head)
	{
		if (pthread_create(&util->head->p_thread, NULL, &print, util->head))
			printf("Error\n");
		usleep(500);
		util->head->last_time_eat = get_time();
		if (util->head->next == util->first)
			break ;
		util->head = util->head->next;
	}
	util->head = util->head->next;
	is_die(util, util->head);
}
