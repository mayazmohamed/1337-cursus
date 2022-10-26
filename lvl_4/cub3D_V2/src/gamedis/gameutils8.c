/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:54:05 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/19 11:52:16 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	getmapheight(t_cub *all)
{
	int	i;

	i = 0;
	while (all->map[i])
		i++;
	all->info.mapheight = i;
}

void	getmapwidth(t_cub *all)
{
	int	i;

	i = 0;
	while (all->map[0][i])
		i++;
	all->info.mapwidth = i;
}

float	ft_abs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	ft_checkdoor(char **map, float x, float y)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{	
			if (map[i][j] == 'D' && (ft_abs(i - y) < 2 && ft_abs(j - x) < 2))
			{
				map[i][j] = 'O';
			}
			if (map[i][j] == 'O' && (ft_abs(i - y) >= 2 || ft_abs(j - x) >= 2))
				map[i][j] = 'D';
		}
	}
}

void	paintceiling(t_cub *all, int top)
{
	int	i;

	i = 0;
	while (i < top)
	{
		my_mlx_pixel_put(all->img, all->ray->colid, i, all->info.cc);
		i++;
	}
}
