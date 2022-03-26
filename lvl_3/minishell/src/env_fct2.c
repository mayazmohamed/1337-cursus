/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fct2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:04:31 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/26 16:04:33 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_env(t_env *head, char *search)
{
	t_env	*tmp;

	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, search))
			return (ft_strdup_garbage(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_env_init(t_env **env, char *s_env[])
{
	int	i;
	int	j;

	i = 0;
	env[0] = NULL;
	if (!s_env[0])
		ft_add_env(&g_all.env_head, ft_new_env(NULL, NULL));
	while (s_env[i])
	{
		j = ft_env_split(s_env[i]);
		ft_add_env(env, ft_new_env(ft_substr(s_env[i], 0, j), \
			ft_substr(s_env[i], j + 1, ft_strlen(s_env[i]))));
		i++;
	}
	signal(SIGINT, handel_ctl);
	signal(SIGQUIT, handel_ctl1);
}
