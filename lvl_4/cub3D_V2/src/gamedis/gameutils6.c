/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:45:47 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/19 10:58:14 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	conserveangle(t_cub *all)
{
	all->ray->rayangle /= (2 * M_PI);
	if (all->ray->rayangle < 0)
		all->ray->rayangle += (2 * M_PI);
}

double	calculdistance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	raydirection(t_cub *all)
{
	if (all->ray->rayangle >= 0 && all->ray->rayangle <= M_PI)
		all->ray->downdirect = 1;
	else
		all->ray->updirect = 1;
	if ((all->ray->rayangle < (0.5 * M_PI))
		|| (all->ray->rayangle > (1.5 * M_PI)))
		all->ray->rightdirect = 1;
	else
		all->ray->leftdirect = 1;
}

void	drawingray(t_cub *all)
{
	int		d[2];
	int		i;
	int		step;
	float	x[2];
	float	inc[2];

	i = 0;
	d[0] = all->tmp->finx - all->tmp->departx ;
	d[1] = all->tmp->finy - all->tmp->departy;
	if (abs(d[0]) > abs(d[1]))
		step = abs(d[0]);
	else
		step = abs(d[1]);
	inc[0] = (float)d[0] / (float)step;
	inc[1] = (float)d[1] / (float)step;
	x[0] = all->tmp->departx;
	x[1] = all->tmp->departy;
	while (i < step && x[0] <= 128 && x[1] <= 128)
	{
		my_mlx_pixel_put(all->img, floor(x[0]), floor(x[1]), 0xeb4034);
		x[0] += inc[0];
		x[1] += inc[1];
		i++;
	}
}

int	checkwall_ray(t_cub *all, double xr, double yr)
{
	int	x;
	int	y;
	int	x_line;

	x = (int)floor(xr / 16);
	y = (int)floor(yr / 16);
	if (y < 0 || y > ft_strleny(all->map))
		return (0);
	if (all->map[y] != NULL)
		x_line = ft_strlen(all->map[y]);
	else
		return (0);
	if (x < 0 && x > x_line)
		return (0);
	if (all->map[y][x] == '1' || all->map[y][x] == ' '
		|| all->map[y][x] == 0 || all->map[y][x] == 'D')
	{
		return (0);
	}
	return (1);
}
