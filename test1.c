#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

typedef struct s_philo
{
	int				_id;
	pid_t			philo;
	size_t			last_meal;
	int				is_full;
	struct s_all	*all;
	struct s_philo	*next;
}	t_philo;

typedef struct s_all
{
	int		philo_cp;
	t_philo	*_first;
	t_philo	*head;
	size_t	death_timer;
	size_t	sleep_timer;
	size_t	eating_timer;
	int		meal_cp;
	int		philo_dead;
	size_t	ground0;
	int		all_full;
	sem_t	*forks;
	sem_t	*writing;
}	t_all;
/******************************************************************************/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *str, int error)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (error);
}

int	ft_check_digits(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rst;

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
/******************************************************************************/
void	ft_sem_init(t_all *all)
{
	sem_unlink("forks");
	sem_unlink("writing");
	all->forks = sem_open("forks", O_CREAT , 0644, all->philo_cp);
	all->writing = sem_open("writing", O_CREAT , 0644, 1);
}
/******************************************************************************/
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
/******************************************************************************/
size_t	ft_timestamp(void)
{
	struct timeval	_t;

	gettimeofday(&_t, NULL);
	return (_t.tv_sec * 1000 + _t.tv_usec / 1000);
}

size_t	ft_time_diff(size_t current, size_t past)
{
	return (current - past);
}

void	ft_print(t_all *all, int _id, char *str)
{
	sem_wait(all->writing);
	if (!all->philo_dead)
		printf ("%10zu ms %3d %s\n",
			ft_time_diff(ft_timestamp(), all->ground0), _id, str);
	sem_post(all->writing);
}

void	ft_sleep(t_all *all, size_t time)
{
	if (!all->philo_dead)
		usleep(time * 1000);
}

void	ft_free_list(t_all *all)
{
	int	i;

	i = 0;
	while (++i <= all->philo_cp)
	{
		kill(all->head->philo, 15);
		free(all->head);
		all->head = all->head->next;
	}
	exit(0);
}
/******************************************************************************/
int	ft_parse_args(t_all *all, char **av)
{
	int	i;

	if (ft_check_digits(av))
		return (1);
	all->philo_cp = ft_atoi(av[1]);
	all->death_timer = ft_atoi(av[2]);
	all->eating_timer = ft_atoi(av[3]);
	all->sleep_timer = ft_atoi(av[4]);
	if (av[5])
		all->meal_cp = ft_atoi(av[5]);
	else
		all->meal_cp = -1;
	all->philo_dead = 0;
	all->all_full = 0;
	ft_sem_init(all);
	i = 0;
	all->head = NULL;
	while (++i <= all->philo_cp)
		ft_lstadd_back(&all->head, ft_new_node(i, all));
	all->_first = all->head;
	return (0);
}
/******************************************************************************/
void	*ft_death(void *p)
{
	t_philo	*philo;
	t_all	*all;

	philo = (t_philo *)p;
	all = philo->all;
	while (1)
	{
		if (ft_time_diff(ft_timestamp(),philo->last_meal) > all->death_timer + 5)
		{
			ft_print(all, philo->_id, "died");
			all->philo_dead = 1;
			sem_wait(all->writing);
			ft_free_list(all);
			exit(1);
		}
		// 	printf("id = %d\n",philo->_id);
		usleep(100);
	}
	return ((void *)0);
}

void	ft_eats(t_all *all, t_philo *philo)
{
	sem_wait(all->forks);
	ft_print(all, philo->_id, "has taken a fork");
	sem_wait(all->forks);
	ft_print(all, philo->_id, "has taken a fork");
	ft_print(all, philo->_id, "is eating");
	philo->last_meal = ft_timestamp();
	ft_sleep(all, all->eating_timer);
	philo->is_full++;
	sem_post(all->forks);
	sem_post(all->forks);
	ft_print(all, philo->_id, "is sleeping");
	ft_sleep(all, all->sleep_timer);
	ft_print(all, philo->_id, "is thinking");
}

void	ft_start(t_philo *philo, t_all *all)
{
	pthread_t death;
	printf("id = %d\n",philo->_id);
	philo->last_meal = ft_timestamp();
	if(pthread_create(&death, NULL, &ft_death, philo))
		exit(ft_putstr("Error : Failed To Create Thread!!", 1));
	if (philo->_id % 2)
		usleep(100);
	while (!all->philo_dead)
		ft_eats(all, philo);
	pthread_join(death, NULL);
	if (all->philo_dead)
	{
		ft_free_list(all);
		exit(1);
	}
	ft_free_list(all);
	exit(0);
}

void	ft_exec(t_all *all)
{
	int i;

	all->ground0 = ft_timestamp();
	i = 0;
	while (++i <= all->philo_cp)
	{
		all->head->philo = fork();
		if (all->head->philo < 0)
			exit(ft_putstr("Error : Forking Failed !!", 1));
		if (all->head->philo == 0)
			ft_start(all->head, all);
		//printf("id = %d\n",all->head->_id);
		usleep(100);
		all->head = all->head->next;
	}
}
/******************************************************************************/
int main(int ac, char *av[])
{
	t_all all;

	if (ac < 5 || ac > 6)
		exit(ft_putstr("Error : Wrong Number Of Arguments!!\n", 1));
	if (ft_parse_args(&all, av))
		exit(ft_putstr("Error : Wrong Arguments Format!!\n", 1));
	ft_exec(&all);
	//while (!all.philo_dead);
	/**************************************/
/*	printf("nb  = %d\n", all.philo_cp);
	printf("death  = %zu\n", all.death_timer);
	printf("eat  = %zu\n", all.eating_timer);
	printf("sleep  = %zu\n", all.sleep_timer);
	printf("cp  = %d\n", all.meal_cp);
	printf("dead  = %d\n", all.philo_dead);
	printf("full  = %d\n", all.all_full);
	t_philo *tmp;
	tmp = all.head;
	while (tmp)
	{
		printf("**************************************\n");
		printf("id = %d\n",tmp->_id);
		printf("meal = %zu\n", tmp->last_meal);
		printf("full = %d\n", tmp->is_full);
		if (tmp->next == all._first)
			break;
		tmp = tmp->next;
	}
	printf("***************** First *********************\n");
		printf("id = %d\n",all._first->_id);
		printf("meal = %zu\n", all._first->last_meal);
		printf("full = %d\n", all._first->is_full);
*/
	return (0);
}
