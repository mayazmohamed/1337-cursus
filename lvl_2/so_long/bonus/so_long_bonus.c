/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:21:08 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 15:06:00 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	calcul_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
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

int	distroy_win(t_map *lst)
{
	mlx_destroy_window(lst->mlx, lst->win);
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	int		fd;
	t_map	m;

	if (!check_file(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("file map not found or permission denied"), 0);
	fill_list(&m, av[1], fd);
	if (!check_map(&m))
		return (0);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, ft_strlen(m.t[0]) * 50, m.line * 50, "l");
	fill_map(m.t, &m);
	mlx_key_hook(m.win, key_hook, &m);
	mlx_hook(m.win, 17, 0, distroy_win, &m);
	mlx_loop_hook(m.mlx, anim_player, &m);
	mlx_loop(m.mlx);
	return (ac);
}
