/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:01:48 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 15:43:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_exit(t_map *lst)
{
	if (lst->t[lst->x][lst->y] == 'C')
		lst->c--;
	if (lst->t[lst->x][lst->y] == 'E' && lst->c == 0)
	{
		mlx_destroy_window(lst->mlx, lst->win);
		exit(0);
	}
}

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
