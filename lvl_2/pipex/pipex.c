/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:42:34 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 12:56:52 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	t_cmd	*cmd;
	int		out;
	int		inf;
	char	*t;
	char	**t1;

	if (ac != 5)
	{
		write(1, "number of arg is not 5\n", 23);
		exit(0);
	}
	out = check_file(ac, av);
	inf = open(av[1], O_RDWR);
	t = ft_substr(env[6], 4, ft_strlen(env[6]));
	t1 = ft_split(t, ':');
	cmd = ft_fill_list(ac, av, t1);
	free(t);
	free_tab(t1);
	exc_cmd(cmd, env, out, inf);
	free_list(cmd);
	return (0);
}
