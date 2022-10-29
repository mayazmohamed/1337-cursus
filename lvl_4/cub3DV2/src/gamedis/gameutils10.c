/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:11:27 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/19 12:11:26 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	locatesprite(t_cub *all)
{
	int	i;
	int	j;
	int	l;
	int	m;
	int	k;

	i = -1;
	l = 0;
	k = 0;
	while (all->map[++i])
	{
		j = -1;
		m = 0;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == 'F')
			{
				all->sprite[k].screenx = m + 8;
				all->sprite[k].screeny = l + 8;
				k++;
			}
			m += 16;
		}
		l += 16;
	}
}

void	randering(t_cub *all, int i)
{
	float	fishangle;

	fishangle = all->sprite[i].dist * cos(all->sprite[i].angle);
	all->sprite[i].spritrheight = (16 / fishangle) * all->distoprojectionplane;
	all->sprite[i].spritewidth = all->sprite[i].spritrheight;
	all->sprite[i].spritetopy = (H / 2) - (all->sprite[i].spritrheight / 2);
	if (all->sprite[i].spritetopy < 0)
		all->sprite[i].spritetopy = 0;
	all->sprite[i].spriteboty = (H / 2) + (all->sprite[i].spritrheight / 2);
	if (all->sprite[i].spriteboty > H)
		all->sprite[i].spriteboty = H;
	all->sprite[i].spritangle = atan2(all->sprite[i].screeny - all->pscreeny,
			all->sprite[i].screenx - all->pscreenx) - all->p->rotationangl;
	all->sprite[i].spritxpos = tan(all->sprite[i].spritangle)
		* all->distoprojectionplane;
	all->sprite[i].spriteleftx = (W / 2) + all->sprite[i].spritxpos
		- (all->sprite[i].spritewidth / 2);
	all->sprite[i].spriterightx = all->sprite[i].spriteleftx
		+ all->sprite[i].spritewidth;
	all->sprite[i].texturewidth = all->spriteimg[all->st].w;
	all->sprite[i].textureheight = all->spriteimg[all->st].h;
}

void	drawing(t_cub *all, int i, int x)
{
	int		y;
	float	dd[2];
	int		spriteoffsety;
	int		spriteoffsetx;
	int		color;

	dd[0] = (all->sprite[i].texturewidth / all->sprite[i].spritewidth);
	spriteoffsetx = (x - all->sprite[i].spriteleftx) * dd[0];
	y = all->sprite[i].spritetopy;
	while (y < all->sprite[i].spriteboty)
	{
		dd[1] = y + (all->sprite[i].spritrheight / 2) - (H / 2);
		spriteoffsety = dd[1] * (all->sprite[i].textureheight
				/ all->sprite[i].spritrheight);
		if (x > 0 && x < W && y > 0 && y < H)
		{
			color = all->spriteimg[all->st].data[spriteoffsety
				* all->sprite[i].texturewidth + spriteoffsetx];
			if (color > 0 && all->sprite[i].dist < all->raydist[x])
				my_mlx_pixel_put(all->img, x, y, color);
		}
		y++;
	}
}

void	randringsprite(t_cub *all)
{
	int	i;
	int	x;

	i = 0;
	spriteimginit(all);
	while (i < all->spritecount)
	{
		if (all->sprite[i].visible)
		{
			randering(all, i);
			x = all->sprite[i].spriteleftx;
			while (x < all->sprite[i].spriterightx)
			{
				drawing(all, i, x);
				x++;
			}
		}
		i++;
	}
}

void	ifspritevisible(t_cub *all, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		all->sprite[i].spritangle = all->p->rotationangl
			- atan2(all->sprite[i].screeny - all->pscreeny,
				all->sprite[i].screenx - all->pscreenx);
		if (all->sprite[i].spritangle > M_PI)
			all->sprite[i].spritangle -= 2 * M_PI;
		if (all->sprite[i].spritangle < -M_PI)
			all->sprite[i].spritangle += 2 * M_PI;
		all->sprite[i].spritangle = ft_abs(all->sprite[i].spritangle);
		if (all->sprite[i].spritangle < (all->ray->fovangle / 2) + all->margin)
		{
			all->sprite[i].visible = 1;
			all->sprite[i].angle = all->sprite[i].spritangle;
			all->sprite[i].dist = calculdistance(all->sprite[i].screenx,
					all->sprite[i].screeny, all->pscreenx, all->pscreeny);
		}
		else
			all->sprite[i].visible = 0;
		i++;
	}
	sorting_sprites(all);
}
