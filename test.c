/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:21:59 by momayaz           #+#    #+#             */
/*   Updated: 2022/02/22 15:41:29 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_env
{
	char *name;
	char *val;
	struct s_env *next;
} t_env;

typedef struct s_list
{
	int		fd[2];
	int		pid;
	int		fd_in;
	int		inf;
	int		out;
	t_env	*env;
	char	*limiter;
	
}	t_list;

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strchr(const char *s, int c)
{
	int	i ;
	char get;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, t_list *lst)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, lst->fd_in);
		s++;
	}
	
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	return (0);
}

char	*find_var(char *s, t_list *lst)
(
	t_env *tmp;
	
	tmp = lst->env;
	while (tmp)
	{
		if (!ft_strcmp(s, tmp->name))
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
)

void check_doll(char *s, t_list *lst)
{
	int place;
	int i;
	int j = 0;
	char *var_env;

	i = 0;
	place = ft_strchr(s, '$');
	if (!place)
		return ;
	place++;
	while (s[place + i] && ft_isalnum(s[place + i]))
		i++;
	/*****************************************************/
	var_env = malloc((i + 1) * sizeof(char));
	if (!var_env)
		return ;
	while (j < i)
	(
		var_env[j] = s[place + j]
		j++;
	)
	var_env[j] = 0;
	/*                          substr                   */
	/*************************************************************/
	
}

void	gnl(int fd, t_list *list)
{
	int		i;
	char	t[8000000];
	char	c;
	char	*tab;

	i = 0;
	write(1, "heredoc> ", 14);
	while (read(fd, &c, 1) > 0)
	{
		t[i++] = c;
		if (c == '\n')
		{
			t[i] = 0;
			tab = ft_strdup(t);
			if (!ft_strcmp(tab, list->limiter))
			{
				free(tab);
				break ;
			}
			write(1, "heredoc> ", 14);
			
			ft_putstr_fd(tab, list->inf);
			free(tab);
			i = 0;
		}
	}
}

void	here_doc( t_list *list, char **av, char **env, int ac)
{
	t_cmd	*cmd;
	char	*t;
	char	**t1;

	if (ac != 6)
		exit(1);
	t = ft_strjoin(av[2], "\n");
	list->limiter = ft_strdup(t);
	free(t);
	if (!access(".tmp", F_OK))
		unlink(".tmp");
	list->inf = open(".tmp", O_CREAT | O_RDWR, 0644);
	gnl(0, list);
	free(list->limiter);
	close(list->inf);
	t = ft_substr(env[6], 4, ft_strlen(env[6]));
	t1 = ft_split(t, ':');
	cmd = ft_fill_list(ac, &av[1], t1);
	free(t);
	list->inf = open(".tmp", O_RDONLY, 0644);
	free_tab(t1);
	ft_exec2(cmd, env, list);
	free_list(cmd);
}