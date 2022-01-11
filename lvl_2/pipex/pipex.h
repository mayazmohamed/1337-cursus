/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:05:31 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:12:28 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<sys/wait.h>

typedef struct s_cmd
{
	char			**cmd;
	char			*path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_list
{
	int		fd[2];
	int		pid;
	int		fd_in;
	int		inf;
	int		out;
	char	*limiter;
}	t_list;
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	gnl(int fd, t_list *list);
void	here_doc( t_list *list, char **av, char **env, int ac);
void	ft_affiche_tab(char **map);
void	ft_affiche(t_cmd *lst);
int		ft_lstcount(t_cmd *lst);
t_cmd	*ft_lstlast(t_cmd *lst);
void	ft_lstadd_front(t_cmd **lst, t_cmd *new);
void	ft_lstadd_back(t_cmd **lst, t_cmd *new);
int		str_len(const char *s, char c);
void	free_tab(char **t);
void	free_list(t_cmd *a);
int		count_world(const char *s, char c);
char	*str_cpy(const char *s, int size);
char	**ft_split(char *s, char c);
t_cmd	*ft_new_node(char *cmd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_path(char *av, char **env);
void	ft_exec1(t_list *list, t_cmd *cmd, char **env);
void	ft_exec2(t_cmd *cmd, char **env, t_list *list);
void	loop_pipe_if(char **env, t_cmd *cmd, int *p, t_list *list);
void	loop_pipe(t_cmd *cmd, char **env, t_list *list);
t_cmd	*test1(char **t, char *arg, t_cmd *list);
t_cmd	*test2(char **t, char *arg, char **env, t_cmd *list);
t_cmd	*ft_fill_list(int ac, char **args, char **env);
int		check_file(int ac, char **av);
void	exc_cmd2(t_cmd *cmd, char **env, int out, t_list *list);
void	exc_cmd(t_cmd *cmd, char **env, int out, int inf);

#endif
