/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_file_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:23:33 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:05:04 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_exec1(t_list *list, t_cmd *cmd, char **env)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Error");
		exit(0);
	}
	if (!pid1)
	{
		dup2(list->fd[0], 0);
		dup2(list->out, 1);
		close(list->fd[0]);
		close(list->fd[1]);
		execve(cmd->next->path, cmd->next->cmd, env);
	}
}

void	ft_exec2(t_cmd *cmd, char **env, t_list *list)
{
	int	pid;

	if (pipe(list->fd) == -1)
	{
		perror("Error");
		exit(0);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	if (!pid)
	{
		dup2(list->fd[1], 1);
		dup2(list->inf, 0);
		close(list->fd[0]);
		close(list->fd[1]);
		close(list->inf);
		execve(cmd->path, cmd->cmd, env);
	}
	ft_exec1(list, cmd, env);
	waitpid(pid, NULL, 0);
}

void	loop_pipe_if(char **env, t_cmd *cmd, int *p, t_list *list)
{
	dup2(list->fd_in, 0);
	if (cmd->next)
		dup2(p[1], 1);
	if (!cmd->next)
		dup2(list->out, 1);
	close(p[0]);
	execve(cmd->path, cmd->cmd, env);
	exit(1);
}

void	loop_pipe(t_cmd *cmd, char **env, t_list *list)
{
	int	p[2];
	int	pid;

	list->fd_in = 0;
	while (cmd)
	{
		pipe(p);
		pid = fork();
		if (pid == -1)
			exit(1);
		else if (pid == 0)
			loop_pipe_if(env, cmd, p, list);
		else
		{
			wait(NULL);
			close(p[1]);
			list->fd_in = p[0];
			cmd = cmd->next;
		}
	}
}
