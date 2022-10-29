/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:35:51 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/02 12:43:11 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	moveleft(t_cub *all)
{
	all->posx += sin(all->p->rotationangl) * 1;
	all->posy -= cos(all->p->rotationangl) * 1;
	if (checkwall(all) == 1)
	{
		all->pscreenx = all->posx;
		all->pscreeny = all->posy;
	}
}

void	moveright(t_cub *all)
{
	all->posx -= sin(all->p->rotationangl) * 1;
	all->posy += cos(all->p->rotationangl) * 1;
	if (checkwall(all) == 1)
	{
		all->pscreenx = all->posx;
		all->pscreeny = all->posy;
	}
}

void	moveup(t_cub *all)
{
	all->posx += cos(all->p->rotationangl) * 1;
	all->posy += sin(all->p->rotationangl) * 1;
	if (checkwall(all) == 1)
	{
		all->pscreenx = all->posx;
		all->pscreeny = all->posy;
	}
}

void	movedown(t_cub *all)
{
	all->posx -= cos(all->p->rotationangl) * 1;
	all->posy -= sin(all->p->rotationangl) * 1;
	if (checkwall(all) == 1)
	{
		all->pscreenx = all->posx;
		all->pscreeny = all->posy;
	}
}

void	moveraytleft(t_cub *all)
{
	all->p->rotationangl += 0.05;
	if (all->p->rotationangl >= (M_PI * 2))
		all->p->rotationangl -= 2 * M_PI;
}
