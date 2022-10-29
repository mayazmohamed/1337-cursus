/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:36:00 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/18 22:11:52 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	pixelmap(t_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 128)
	{
		j = 0;
		while (j < 128)
		{
			my_mlx_pixel_put(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	checkplayer(t_cub *all, int ch)
{
	if (ch == 0)
	{
		all->h = 0;
		all->yp = -1;
		while (all->map[++all->yp])
		{
			all->xp = -1;
			all->w = 0;
			while (all->map[all->yp][++all->xp])
			{
				if (all->map[all->yp][all->xp] == 'N'
					|| all->map[all->yp][all->xp] == 'S'
					|| all->map[all->yp][all->xp] == 'W'
					|| all->map[all->yp][all->xp] == 'E')
				{
					fillplayer(all);
					return (1);
				}
				all->w += 16;
			}
			all->h += 16;
		}
	}
	return (0);
}

t_player	*iniatialiserp(t_cub *all)
{
	t_player	*p;

	p = (t_player *) malloc(sizeof(t_player));
	p->walkdirectionx = 0;
	p->walkdirectiony = 0;
	p->turndirection = 0;
	p->movespeed = 2.0;
	p->movestep = 0.0;
	p->radius = 0;
	p->rotationangl = -1;
	p->rotationspeed = 2 * (M_PI / 180);
	checkplayer(all, 0);
	p->xp = all->xp;
	p->yp = all->yp;
	return (p);
}

void	detectang(t_cub *all)
{
	if (all->pp == 'N')
		all->p->rotationangl = M_PI_2;
	else if (all->pp == 'S')
		all->p->rotationangl = M_PI * 3 / 2;
	else if (all->pp == 'W')
		all->p->rotationangl = M_PI;
	else
		all->p->rotationangl = 0;
}

void	drawingline(t_cub *all)
{
	int		dx;
	int		dy;
	int		i;

	i = 0;
	dx = all->dirx - all->xp;
	dy = all->diry - all->yp;
	if (abs(dx) > abs(dy))
		all->norm->step = abs(dx);
	else
		all->norm->step = abs(dy);
	all->norm->incx = dx / (float)all->norm->step;
	all->norm->incy = dy / (float)all->norm->step;
	all->norm->x = (float)64;
	all->norm->y = (float)64;
	while (i < all->norm->step)
	{
		my_mlx_pixel_put(all->img, round(all->norm->x),
			round(all->norm->y), 0x0D1700);
		all->norm->x += all->norm->incx;
		all->norm->y += all->norm->incy;
		i++;
	}
}
