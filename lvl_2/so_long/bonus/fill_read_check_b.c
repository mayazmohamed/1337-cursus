/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_read_check_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:57:08 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 13:49:33 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**fil_tab(int line, int fd)
{
	int		i;
	char	**t;

	i = 0;
	t = malloc((line + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	while (i < line)
	{
		t[i] = read_map(fd);
		i++;
	}
	t[i] = 0;
	return (t);
}

void	fill_list(t_map *lst, char *av, int fd)
{
	lst->c = 0;
	lst->m = 0;
	lst->e = 0;
	lst->p = 0;
	lst->m = 0;
	lst->f = 0;
	lst->line = cont_line(av);
	lst->t = fil_tab(lst->line, fd);
	lst->lent = ft_strlen(lst->t[0]);
}

int	read_map_elem(t_map *lst, int i)
{
	int	j;

	if (lst->t[i][0] != '1' || lst->t[i][ft_strlen(lst->t[i]) - 1] != '1')
		return (printf("invalid map2"), 0);
	j = 0;
	while (lst->t[i][j])
	{
		if (lst->t[i][j] != '0' && lst->t[i][j] != '1' && lst->t[i][j] != 'C'
			&& lst->t[i][j] != 'E' && lst->t[i][j] != 'P'
			&& lst->t[i][j] != 'F')
			return (printf("invalid map3"), 0);
		if (lst->t[i][j] == 'C')
			lst->c++;
		if (lst->t[i][j] == 'E')
			lst->e++;
		if (lst->t[i][j] == 'P')
			lst->p++;
		if (lst->p > 1)
			return (printf("number of the player's is more then 1."), 0);
		if (lst->t[i][j] == 'F')
			lst->f++;
		j++;
	}
	return (1);
}

int	check_map(t_map *lst)
{
	int	i;

	i = 0;
	while (lst->t[i])
	{
		if (i == 0 || i == lst->line - 1)
		{
			if (ft_strcmp(lst->t[i], '1'))
				return (printf("invalid map1"), 0);
		}
		else
		{
			if (!read_map_elem(lst, i))
				return (0);
		}
		if (ft_strlen(lst->t[0]) != ft_strlen(lst->t[i]))
		{
			printf("invalid map4");
			return (0);
		}
		i++;
	}
	if (lst->f == 0)
		return (printf("number of the enemy's is 0."), 0);
	return (1);
}

int	check_file(char *t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	i--;
	if (!(t[i] == 'r' && t[i - 1] == 'e' && t[i - 2] == 'b' && t[i - 3] == '.'))
		return (printf("file map must be .ber extension."), 0);
	return (1);
}
