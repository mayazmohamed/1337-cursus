/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:33:01 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 15:33:03 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_init(t_all *all)
{
	sem_unlink("forks");
	sem_unlink("writing");
	all->forks = sem_open("forks", O_CREAT, 0644, all->philo_cp);
	all->writing = sem_open("writing", O_CREAT, 0644, 1);
}

t_philo	*ft_new_node(int _id, t_all *all)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->_id = _id;
	new->last_meal = 0;
	new->is_full = 0;
	new->all = all;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*cp;

	if (!new)
		return ;
	if (!lst[0])
	{
		lst[0] = new;
		new->next = new;
		return ;
	}
	cp = lst[0];
	while (cp->next != lst[0])
		cp = cp->next;
	cp->next = new;
	new->next = lst[0];
}

size_t	ft_timestamp(void)
{
	struct timeval	_t;

	gettimeofday(&_t, NULL);
	return (_t.tv_sec * 1000 + _t.tv_usec / 1000);
}
