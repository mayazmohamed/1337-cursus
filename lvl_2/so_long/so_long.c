/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:25:37 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 16:18:33 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	m.win = mlx_new_window(m.mlx, ft_strlen(m.t[0]) * 50, m.line * 50, "S");
	fill_map(m.t, &m);
	mlx_key_hook(m.win, key_hook, &m);
	mlx_hook(m.win, 17, 0, distroy_win, &m);
	mlx_loop(m.mlx);
	return (ac);
}
