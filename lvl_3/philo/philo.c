/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:04:49 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/12 16:39:41 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	int	ph_id;
    pthread_t p_thread;
    pthread_mutex_t fork_id;
    int is_eat;
    size_t last_time_eat;
	struct s_util *util;
    struct s_philo *next;
}   t_philo;

typedef struct s_util
{
	struct s_philo *first;
	struct s_philo *head;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	int		number_eat;
	size_t start_time;

} t_util;


void	ft_affiche(t_philo *lst)
{
	return ;
	if (!lst)
		return ;
	while (lst)
	{
		printf("philo number : %d\n", lst->ph_id);
		//printf("fork number : %d\n", lst->fork_id);
		printf("philo is eat : %d\n", lst->is_eat);
		//printf("last time philo eat : %d\n", lst->last_time_eat);

		lst = lst->next;
		printf("--------------------------\n");
	}
}

void	free_list(t_philo *a)
{
    t_philo *tmp;

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
    new->is_eat = 0;
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

int check_args(char **args)
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

size_t get_time(void)
{
	struct timeval tv;
 	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void *print(void *philo)
{
	t_philo *tmp;

	tmp = (t_philo *)philo;
	
	while (1)
	{
		printf("---------------\nphilo in thread %d\n-----------------------\n", tmp->ph_id);
		pthread_mutex_lock(&tmp->fork_id);
		pthread_mutex_lock(&tmp->next->fork_id);
			printf("%zu ____ philo %d is eating\n", get_time() - tmp->util->start_time, tmp->ph_id);
		sleep(1);
		pthread_mutex_unlock(&tmp->fork_id);
		pthread_mutex_unlock(&tmp->next->fork_id);
		sleep(1);
	}
	return (0);
}

void loop_thread(t_util *util)
{
	util->start_time = get_time();
	while (util->head)
	{
		if (pthread_create(&util->head->p_thread, NULL, &print, util->head))
			printf("Error\n");
	//	pthread_detach(philo->p_thread);
		usleep(500);
		if (util->head->next == util->first)
			break ;
		util->head = util->head->next;
	}
}

void fill_util_struct(t_util *util, char **av)
{
	util->time_to_die = ft_atoi(av[2]);
	util->time_to_eat = ft_atoi(av[3]);
	util->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		util->number_eat = ft_atoi(av[5]);
}

int main(int ac, char *av[])
{
     t_util util;
    
    if ((ac != 6 && ac != 5))
        return (printf("wrong number of argument."), 0);
	fill_util_struct(&util, av);
    util.head = ft_devide_args(av, &util);
    if (!util.head)
        return (0);
	util.first = util.head;
	loop_thread(&util);
	while(1);
	//ft_affiche(philo_list);
    
}