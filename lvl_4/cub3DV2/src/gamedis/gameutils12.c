/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:36:25 by momayaz           #+#    #+#             */
/*   Updated: 2022/10/28 09:30:07 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	paintfloor(t_cub *all, int bottom)
{
	int	i;

	i = bottom;
	while (i < H)
	{
		my_mlx_pixel_put(all->img, all->ray->colid, i, all->info.fc);
		i++;
	}
}

int	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	getwaltex(t_cub *all)
{
	if (all->ray->updirect && all->pos->hori_f)
		all->l7aj = 1;
	else if (all->ray->downdirect && all->pos->hori_f)
		all->l7aj = 0;
	else if (all->ray->leftdirect && all->pos->verti_f)
		all->l7aj = 3;
	else if (all->ray->rightdirect && all->pos->verti_f)
		all->l7aj = 2;
	if (all->map[(int)(all->pos->po.y / 16)][(int)(all->pos->po.x / 16)] == 'D')
		all->l7aj = 4;
	if ((all->ray->updirect && all->pos->hori_f)
		&& all->map[(int)((all->pos->po.y) / 16) - 1]
		[(int)(all->pos->po.x / 16)] == 'D')
		all->l7aj = 4;
	if ((all->ray->leftdirect && all->pos->verti_f)
		&& all->map[(int)((all->pos->po.y)
			/ 16)][(int)(all->pos->po.x / 16) - 1] == 'D')
		all->l7aj = 4;
}

void	paintwalltex(t_cub *all, int i, int bottomofwall, double wallheight)
{
	double	offsetx;
	int		d;
	int		offsety;
	int		txtcoll;

	while (i < bottomofwall)
	{
		if (all->hitv)
			offsetx = all->pos->po.y / 16;
		else
			offsetx = all->pos->po.x / 16;
		offsetx -= floor(offsetx);
		offsetx *= all->texture[all->l7aj].w;
		d = i + (wallheight / 2) - (H / 2);
		offsety = d * ((float) all->texture[all->l7aj].w / wallheight);
		if (all->l7aj >= 0 && all->l7aj < 6)
		{
			txtcoll = (int)all->texture[all->l7aj].data
			[(all->texture[all->l7aj].w * offsety) + (int)offsetx];
			my_mlx_pixel_put(all->img, all->ray->colid, i, txtcoll);
		}
		i++;
	}
	all->l7aj = 0;
}

void	renderthreed(t_cub *all)
{
	int		i;
	int		wallstripheight;
	int		topofwall[2];
	double	correctdistance;
	double	wallheight;

	i = 0;
	correctdistance = 0;
	correctdistance = all->ray->distance * cos(
			all->ray->rayangle - all->p->rotationangl);
	all->distoprojectionplane = (W / 2) / tan(all->ray->fovangle / 2);
	wallheight = (16 / correctdistance) * all->distoprojectionplane;
	wallstripheight = (int)wallheight;
	topofwall[0] = (H / 2.0) - (wallstripheight / 2.0);
	topofwall[1] = (H / 2.0) + (wallstripheight / 2.0);
	if (topofwall[0] < 0 || topofwall[0] > H)
		topofwall[0] = 0;
	if (topofwall[1] > H || topofwall[1] < 0)
		topofwall[1] = H;
	i = topofwall[0];
	paintceiling(all, topofwall[0]);
	paintfloor(all, topofwall[1]);
	getwaltex(all);
	paintwalltex(all, i, topofwall[1], wallheight);
}
