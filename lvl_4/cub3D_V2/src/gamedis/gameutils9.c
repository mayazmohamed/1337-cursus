/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:56:43 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/23 18:11:18 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_drawrays	*lstnew(double x, double y, double a, double b)
{
	t_drawrays	*element;

	element = (t_drawrays *)malloc(sizeof(t_drawrays));
	if (!element)
		return (NULL);
	element->departx = x;
	element->departy = y;
	element->finx = a;
	element->finy = b;
	element->next = NULL;
	return (element);
}

void	lstaddback(t_drawrays **header, t_drawrays *new)
{
	t_drawrays	*p;

	p = NULL;
	if (header)
	{
		if ((*header) == NULL)
			(*header) = new;
		else
		{
			p = *header;
			while (p->next != NULL)
				p = p->next;
			p->next = new;
		}
	}
}

void	initialrayvar(t_cub *all)
{
	all->ray->colid = 0;
	all->ray->fovangle = 60 * (M_PI / 180);
	all->ray->wallstrip = 1;
	all->ray->numrays = W / all->ray->wallstrip;
	all->ray->rayangle = all->p->rotationangl - (all->ray->fovangle / 2);
	all->ray->distance = 0;
	all->ray->wallhitx = 0;
	all->ray->wallhity = 0;
	all->ray->downdirect = false;
	all->ray->updirect = false;
	all->ray->leftdirect = false;
	all->ray->rightdirect = false;
}

void	fovminimap(t_cub *all)
{
	double	inc_angle;
	t_glpos	glpos;

	inc_angle = all->ray->fovangle / W;
	initialrayvar(all);
	calctuxter(all);
	ft_checkdoor(all->map, all->posx / 16, all->posy / 16);
	all->hitindex = 0;
	while (all->ray->colid < all->ray->numrays)
	{
		hintercept(all, all->ray->rayangle, &glpos);
		renderthreed(all);
		all->ray->rayangle += inc_angle;
		all->ray->colid++;
	}
}

void	affichminimap(t_cub *all, int ch)
{
	int	x;
	int	y;

	all->node = NULL;
	checkplayer(all, ch);
	x = all->pscreenx - 64;
	y = all->pscreeny - 64;
	all->distancexx = x;
	all->distanceyy = y;
	all->posx = all->pscreenx;
	all->posy = all->pscreeny;
	if (ch == 0)
	{
		all->p = iniatialiserp(all);
		detectang(all);
	}
	fovminimap(all);
	if (all->game_mode == 'b')
	{
		paintmap(all, all->img, ch);
		paintplayer(all, ch);
	}
	randringsprite(all);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->img->img, 0, 0);
}
