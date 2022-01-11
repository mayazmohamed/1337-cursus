/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:42:32 by momayaz           #+#    #+#             */
/*   Updated: 2022/01/10 12:12:46 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	put_player_img(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->player[0], j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->player[0]);
}

void	put_c_img(t_map *m, int i, int j)
{
	mlx_put_image_to_window(m->mlx, m->win, m->colect, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->colect);
}

void	fill_map_else(char **t, t_map *m, int i, int j)
{
	int	w;
	int	h;

	m->player[0] = mlx_xpm_file_to_image(m->mlx, "./img/player1.xpm", &w, &h);
	m->player[1] = mlx_xpm_file_to_image(m->mlx, "./img/rp.xpm", &w, &h);
	m->player[2] = mlx_xpm_file_to_image(m->mlx, "./img/pd.xpm", &w, &h);
	m->floor = mlx_xpm_file_to_image(m->mlx, "./img/floor1.xpm", &w, &h);
	mlx_put_image_to_window(m->mlx, m->win, m->floor, j * 50, i * 50);
	mlx_destroy_image(m->mlx, m->floor);
	if (t[i][j] == 'C')
	{
		m->colect = mlx_xpm_file_to_image(m->mlx, "./img/colect.xpm", &w, &h);
		put_c_img(m, i, j);
	}
	if (t[i][j] == 'P')
		put_player_img(m, i, j);
	if (t[i][j] == 'E')
	{
		if (m->c == 0)
			m->door = mlx_xpm_file_to_image(m->mlx, "./img/gd.xpm", &w, &h);
		else
			m->door = mlx_xpm_file_to_image(m->mlx, "./img/rrd.xpm", &w, &h);
		mlx_put_image_to_window(m->mlx, m->win, m->door, j * 50, i * 50);
		mlx_destroy_image(m->mlx, m->door);
	}
}

void	fill_map(char **t, t_map *m)
{
	int	i;
	int	j;
	int	w;
	int	h;

	i = 0;
	while (t[i])
	{
		j = 0;
		while (t[i][j])
		{
			if (t[i][j] == '1')
			{
				m->wl = mlx_xpm_file_to_image(m->mlx, "./img/w.xpm", &w, &h);
				mlx_put_image_to_window(m->mlx, m->win, m->wl, j * 50, i * 50);
				mlx_destroy_image(m->mlx, m->wl);
			}
			else
			{
				fill_map_else(t, m, i, j);
			}
			j++;
		}
		i++;
	}
}
