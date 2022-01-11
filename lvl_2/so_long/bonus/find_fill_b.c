/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fill_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:58:17 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 15:45:17 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_f_pos(char **t, int *i, int *j)
{
	while (t[*i])
	{
		(*j) = 0;
		while (t[*i][*j])
		{
			if (t[*i][*j] == 'F')
				return (1);
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

void	put_p_image(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->player[0], j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->player[0]);
}

void	put_c_image(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->colect, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->colect);
}

void	put_f_image(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->f, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->f);
}

void	fill_map_else(char **t, t_map *m, int i, int j)
{
	int	w;
	int	h;

	m->player[0] = mlx_xpm_file_to_image(m->mlx, "./img/player1.xpm", &w, &h);
	m->player[1] = mlx_xpm_file_to_image(m->mlx, "./img/rp.xpm", &w, &h);
	m->floor = mlx_xpm_file_to_image(m->mlx, "./img/floor1.xpm", &w, &h);
	m->colect = mlx_xpm_file_to_image(m->mlx, "./img/colect.xpm", &w, &h);
	m->f = mlx_xpm_file_to_image(m->mlx, "./img/F.xpm", &w, &h);
	mlx_put_image_to_window(m->mlx, m->win, m->floor, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->floor);
	if (t[i][j] == 'C')
		put_c_image(m, i, j);
	if (t[i][j] == 'P')
		put_p_image(m, i, j);
	if (t[i][j] == 'E')
	{
		if (m->c == 0)
			m->door = mlx_xpm_file_to_image(m->mlx, "./img/gd.xpm", &w, &h);
		else
			m->door = mlx_xpm_file_to_image(m->mlx, "./img/rrd.xpm", &w, &h);
		mlx_put_image_to_window(m->mlx, m->win, m->door, j * 50, i * 50);
		mlx_destroy_image(m->mlx, m->door);
	}
	if (t[i][j] == 'F')
		put_f_image(m, i, j);
}
