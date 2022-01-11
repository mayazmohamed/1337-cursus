/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:42:34 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:08:07 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char *av[], char *env[])
{
	t_cmd	*cmd;
	t_list	list;
	char	*t;
	char	**t1;

	list.out = check_file(ac, av);
	if (!ft_strcmp(av[1], "here_doc"))
		here_doc(&list, av, env, ac);
	else
	{
		if (access(av[1], F_OK) == -1)
		{
			write(1, "the infile is not exist\n", 24);
			exit(0);
		}
		list.inf = open(av[1], O_RDWR);
		t = ft_substr(env[6], 4, ft_strlen(env[6]));
		t1 = ft_split(t, ':');
		cmd = ft_fill_list(ac, av, t1);
		free(t);
		free_tab(t1);
		loop_pipe(cmd, env, &list);
		free_list(cmd);
	}
	return (0);
}
