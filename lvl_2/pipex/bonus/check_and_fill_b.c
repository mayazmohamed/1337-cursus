/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:06:09 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:02:43 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_path(char *av, char **env)
{
	int		i;
	char	*t;
	char	*t1;

	i = 0;
	while (env[i])
	{
		t = ft_strjoin(env[i], "/");
		t1 = ft_strjoin(t, av);
		free(t);
		if (access(t1, F_OK) == 0)
		{
			free(t1);
			return (env[i]);
		}
		free(t1);
		i++;
	}
	return (NULL);
}

t_cmd	*test1(char **t, char *arg, t_cmd *list)
{
	char	*t1;
	t_cmd	*tmp;

	t1 = ft_strrchr(arg, '/');
	tmp = ft_new_node(t1);
	if (!tmp)
	{
		free_list(list);
		free_tab(t);
		return (NULL);
	}
	tmp->path = ft_strdup(t[0]);
	return (tmp);
}

t_cmd	*test2(char **t, char *arg, char **env, t_cmd *list)
{
	t_cmd	*tmp;
	char	*join;
	char	*t1;

	t1 = get_path(t[0], env);
	if (!t1)
	{
		write(1, "command not found\n", 18);
		exit(0);
	}
	tmp = ft_new_node(arg);
	if (!tmp)
	{
		free_list(list);
		free_tab(t);
		return (NULL);
	}
	join = ft_strjoin(t1, "/");
	tmp->path = ft_strjoin(join, t[0]);
	free(join);
	return (tmp);
}

t_cmd	*ft_fill_list(int ac, char **args, char **env)
{
	t_cmd	*tmp;
	t_cmd	*list;
	char	**t;
	int		i;

	list = NULL;
	i = 2;
	while (args[i] && i < ac - 1)
	{
		t = ft_split(args[i], ' ');
		if (!access(t[0], F_OK))
			tmp = test1(t, args[i], list);
		else
			tmp = test2(t, args[i], env, list);
		ft_lstadd_back(&list, tmp);
		i++;
		free_tab(t);
	}
	return (list);
}

int	check_file(int ac, char **av)
{
	int	fd;

	fd = open(av[ac - 1], O_CREAT, 0644);
	close(fd);
	fd = open(av[ac - 1], O_RDWR | O_APPEND);
	return (fd);
}
