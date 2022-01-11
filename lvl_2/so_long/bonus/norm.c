/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:43:11 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 15:45:23 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_p_pos(char **t, int *i, int *j)
{
	while (t[*i])
	{
		(*j) = 0;
		while (t[*i][*j])
		{
			if (t[*i][*j] == 'P')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

int	check_player_pos(t_map *lst, int key)
{
	int	i;
	int	j;

	i = 0;
	while (lst->t[i])
	{
		j = 0;
		while (lst->t[i][j])
		{
			if (lst->t[i][j] == 'P')
			{
				if (!check_pos_val(lst, key, i, j))
					return (0);
				if (!check_pos_val2(lst, key, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	rand_move1(t_map *map, int i, int j)
{
	if (map->t[i][j + 1] != '1' && map->t[i][j + 1] != 'P'
			&& map->t[i][j + 1] != 'C' && map->t[i][j + 1] != 'E')
	{
		map->t[i][j + 1] = 'F';
		map->t[i][j] = '0';
		return (0);
	}
	if (map->t[i + 1][j] != '1' && map->t[i + 1][j] != 'P'
			&& map->t[i + 1][j] != 'C' && map->t[i + 1][j] != 'E')
	{
		map->t[i + 1][j] = 'F';
		map->t[i][j] = '0';
		return (0);
	}
	return (1);
}

void	rand_move(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_f_pos(map->t, &i, &j);
	if (map->t[i][j - 1] != '1' && map->t[i][j - 1] != 'P'
		&& map->t[i][j - 1] != 'C' && map->t[i][j - 1] != 'E')
	{
		map->t[i][j - 1] = 'F';
		map->t[i][j] = '0';
		return ;
	}
	if (map->t[i - 1][j] != '1' && map->t[i - 1][j] != 'P'
			&& map->t[i - 1][j] != 'C' && map->t[i - 1][j] != 'E')
	{
		map->t[i - 1][j] = 'F';
		map->t[i][j] = '0';
		return ;
	}
	if (!rand_move1(map, i, j))
		return ;
}
