/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:19:38 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 14:37:12 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_affiche(t_philo *lst)
{
	return ;
	if (!lst)
		return ;
	while (lst)
	{
		printf("philo number : %d\n", lst->ph_id);
		printf("philo is eat : %d\n", lst->is_eat);
		lst = lst->next;
		printf("--------------------------\n");
	}
}

void	free_list(t_philo *a)
{
	t_philo	*tmp;

	while (a)
	{
		tmp = a->next;
		if (a)
			free(a);
		a = tmp;
	}
}

t_philo	*ft_new_node(int value, t_util *util)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->ph_id = value;
	new->is_eat = -1;
	new->last_time_eat = 0;
	new->util = util;
	pthread_mutex_init(&new->fork_id, NULL);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	if (!new)
		return ;
	if (!lst[0])
	{
		lst[0] = new;
		new->next = new;
		return ;
	}
	tmp = lst[0];
	while (tmp->next != lst[0])
		tmp = tmp->next;
	tmp->next = new;
	new->next = lst[0];
}
