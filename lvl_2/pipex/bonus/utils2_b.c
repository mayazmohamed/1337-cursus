/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:00:56 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/11 13:09:07 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	p = malloc(len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	while (len--)
		p[i++] = s[start++];
	p[i] = 0;
	return (p);
}

void	ft_affiche_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_affiche(t_cmd *lst)
{
	return ;
	if (!lst)
		return ;
	while (lst)
	{
		ft_affiche_tab(lst->cmd);
		printf("path = %s\n", lst->path);
		lst = lst->next;
		printf("--------------------------\n");
	}
}

void	free_list(t_cmd *a)
{
	while (a)
	{
		if (a)
		{
			if (a->cmd)
				free_tab(a->cmd);
			if (a->path)
				free(a->path);
			free(a);
		}
		a = a->next;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1 * sizeof(char));
	if (!p)
		return (0);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = 0;
	return (p);
}
