/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:45:20 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 10:36:27 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pos_vali_2(t_map *lst, int key, int i, int j)
{
	if (key == 1)
	{
		if (lst->t[i + 1][j] == '1' || (lst->t[i + 1][j] == 'E' && lst->c))
			return (0);
		if (lst->t[i + 1][j] == 'F')
		{
			mlx_destroy_window(lst->mlx, lst->win);
			exit(0);
		}
		lst->x = i + 1;
		lst->y = j;
		check_exit(lst);
	}
	return (1);
}

int	check_pos_vali_1(t_map *lst, int key, int i, int j)
{
	if (key == 2)
	{
		if (lst->t[i][j + 1] == '1' || (lst->t[i][j + 1] == 'E' && lst->c))
			return (0);
		if (lst->t[i][j + 1] == 'F')
		{
			mlx_destroy_window(lst->mlx, lst->win);
			exit(0);
		}
		lst->x = i;
		lst->y = j + 1;
		check_exit(lst);
	}
	return (1);
}

int	check_pos_val(t_map *lst, int key, int i, int j)
{
	if (key == 13)
	{
		if (lst->t[i - 1][j] == '1' || (lst->t[i - 1][j] == 'E' && lst->c))
			return (0);
		if (lst->t[i - 1][j] == 'F')
		{
			mlx_destroy_window(lst->mlx, lst->win);
			exit(0);
		}
		lst->x = i - 1;
		lst->y = j;
		check_exit(lst);
	}
	if (!check_pos_vali_1(lst, key, i, j))
		return (0);
	if (!check_pos_vali_2(lst, key, i, j))
		return (0);
	return (1);
}

int	check_pos_val2(t_map *lst, int key, int i, int j)
{
	if (key == 0)
	{
		if (lst->t[i][j - 1] == '1' || (lst->t[i][j - 1] == 'E' && lst->c))
			return (0);
		if (lst->t[i][j - 1] == 'F')
		{
			mlx_destroy_window(lst->mlx, lst->win);
			exit(0);
		}
		lst->x = i;
		lst->y = j - 1;
		check_exit(lst);
	}
	return (1);
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
