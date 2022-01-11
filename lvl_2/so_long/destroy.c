/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:46:26 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 11:35:05 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	distroy_win(t_map *lst)
{
	mlx_destroy_window(lst->mlx, lst->win);
	exit(0);
	return (0);
}

void	key_hook_1(int key, t_map *map)
{
	if (key == 2 && check_player_pos(map, key))
	{
		mlx_clear_window(map->mlx, map->win);
		map->t[map->x][map->y] = 'P';
		map->t[map->x][(map->y) - 1] = '0';
		map->m++;
		printf("%d moves\n", map->m);
	}
	if (key == 1 && check_player_pos(map, key))
	{
		mlx_clear_window(map->mlx, map->win);
		map->t[map->x][map->y] = 'P';
		map->t[(map->x) - 1][map->y] = '0';
		map->m++;
		printf("%d moves\n", map->m);
	}
	if (key == 0 && check_player_pos(map, key))
	{
		mlx_clear_window(map->mlx, map->win);
		map->t[map->x][map->y] = 'P';
		map->t[map->x][(map->y) + 1] = '0';
		map->m++;
		printf("%d moves\n", map->m);
	}
}

int	key_hook(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	if (key == 13 && check_player_pos(map, key))
	{
		mlx_clear_window(map->mlx, map->win);
		map->t[map->x][map->y] = 'P';
		map->t[map->x + 1][map->y] = '0';
		map->m++;
		printf("%d moves\n", map->m);
	}
	key_hook_1(key, map);
	fill_map(map->t, map);
	return (0);
}
