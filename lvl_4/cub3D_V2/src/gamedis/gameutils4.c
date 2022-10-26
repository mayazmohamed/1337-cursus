/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:45:40 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/18 22:14:40 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	paintplayer(t_cub *all, int ch)
{
	int			i;
	int			j;

	(void)ch;
	i = 0;
	all->tmp = all->node;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(all->img, 64, 64, 0xFD1700);
			j++;
		}
		i++;
	}
	while (all->tmp->next)
	{
		drawingray(all);
		all->tmp = all->tmp->next;
	}
	drawingray(all);
}

int	checkwall(t_cub *all)
{
	int	x;
	int	y;
	int	x_line;

	x = floor(all->posx / 16);
	y = floor(all->posy / 16);
	if (y < 0 && y > ft_strleny(all->map))
		return (0);
	if (all->map[y] != NULL)
		x_line = ft_strlen(all->map[y]);
	else
		return (0);
	if (x < 0 && x > x_line)
		return (0);
	if (all->map[y][x] == '1' || all->map[y][x] == ' '
		|| all->map[y][x] == 0 || all->map[y][x] == 'F')
	{
		return (0);
	}
	return (1);
}

void	moveraytright(t_cub *all)
{
	all->p->rotationangl -= 0.05;
	if (all->p->rotationangl <= 0)
		all->p->rotationangl += 2 * M_PI;
}

void	updat_data(t_cub **all)
{
	double	step;

	step = (*all)->p->walkdirectiony * 2;
	(*all)->p->rotationangl += (*all)->p->turndirection * (2 * M_PI / 180);
	(*all)->p->rotationangl = fmod((*all)->p->rotationangl, 2 * M_PI);
	if ((*all)->p->rotationangl < 0)
		(*all)->p->rotationangl += 2 * M_PI;
	(*all)->posx += cos((*all)->p->rotationangl) * step;
	(*all)->posy += sin((*all)->p->rotationangl) * step;
	if (checkwall(*all) == 1)
	{
		(*all)->pscreenx = (*all)->posx;
		(*all)->pscreeny = (*all)->posy;
	}
	step = (*all)->p->walkdirectionx * 2;
	(*all)->posx -= sin((*all)->p->rotationangl) * step;
	(*all)->posy += cos((*all)->p->rotationangl) * step;
	if (checkwall(*all) == 1)
	{
		(*all)->pscreenx = (*all)->posx;
		(*all)->pscreeny = (*all)->posy;
	}
}

int	keyrelease(int key, t_cub *all)
{
	if (key == 124)
		all->p->turndirection = 0;
	else if (key == 123)
		all->p->turndirection = 0;
	if (key == 0)
		all->p->walkdirectionx = 0;
	else if (key == 2)
		all->p->walkdirectionx = 0;
	else if (key == 1)
		all->p->walkdirectiony = 0;
	else if (key == 13)
		all->p->walkdirectiony = 0;
	return (0);
}
