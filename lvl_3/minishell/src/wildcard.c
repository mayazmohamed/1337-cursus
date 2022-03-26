/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:06:04 by momayaz           #+#    #+#             */
/*   Updated: 2022/03/26 16:06:06 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*str_cpy2(char *s)
{
	size_t	len;
	char	*t;
	int		i;

	len = ft_strlen(s);
	i = 0;
	t = malloc((len + 1) * sizeof(char));
	if (!t)
		return (NULL);
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

static int	count_tab_len(void)
{
	DIR				*dir;
	struct dirent	*wild;
	int				i;

	dir = opendir(".");
	i = 0;
	if (dir == NULL)
		return (-1);
	wild = readdir(dir);
	while (wild)
	{
		i++;
		wild = readdir(dir);
	}
	closedir(dir);
	return (i);
}

char	**alloc_tab(t_wild w)
{
	w.len = count_tab_len();
	w.i = 0;
	w.t = malloc((w.len + 1) * sizeof(char *));
	if (!w.t)
		return (NULL);
	w.dir = opendir(".");
	if (w.dir == NULL)
		return (NULL);
	w.wild = readdir(w.dir);
	while (w.wild)
	{
		if (!ft_strcmp(w.wild->d_name, ".") || !ft_strcmp(w.wild->d_name, ".."))
		{
			w.wild = readdir(w.dir);
			continue ;
		}
		w.t[w.i] = str_cpy2(w.wild->d_name);
		if (!w.t[w.i])
			return (free_tab(w.t), NULL);
		w.i++;
		w.wild = readdir(w.dir);
	}
	closedir(w.dir);
	w.t[w.i] = 0;
	return (w.t);
}
