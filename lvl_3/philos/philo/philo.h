/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:02:10 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/04 15:04:43 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				ph_id;
	pthread_t		p_thread;
	pthread_mutex_t	fork_id;
	int				is_eat;
	size_t			last_time_eat;
	struct s_util	*util;
	struct s_philo	*next;
}	t_philo;

typedef struct s_util
{
	struct s_philo	*first;
	struct s_philo	*head;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_eat;
	int				stop_thread;
	size_t			start_time;
	pthread_mutex_t	writing;
}	t_util;

void	ft_print(t_util *all, int _id, char *str);
void	ft_affiche(t_philo *lst);
void	free_list(t_philo *a);
t_philo	*ft_new_node(int value, t_util *util);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
int		ft_isdigit(char c);
long	ft_atoi(char *str);
int		check_args(char **args);
t_philo	*ft_fill_stack(char *av, t_util *util);
t_philo	*ft_devide_args(char **args, t_util *util);
size_t	get_time(void);
void	*print(void *philo);
void	is_die( t_util *util, t_philo *philo);
void	loop_thread(t_util *util);
void	fill_util_struct(t_util *util, char **av);
#endif
