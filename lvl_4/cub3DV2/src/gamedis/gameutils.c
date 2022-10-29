/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momayaz <momayaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:02:01 by ygbouri           #+#    #+#             */
/*   Updated: 2022/10/18 18:42:43 by momayaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	intercephori(t_cub *all, t_glpos *glpos, double angle, int len)
{
	glpos->player.x = all->pscreenx;
	glpos->player.y = all->pscreeny;
	glpos->intercept.y = floor(glpos->player.y / 16) * 16;
	if (all->ray->downdirect)
		glpos->intercept.y += 16;
	glpos->intercept.x = glpos->player.x + (glpos->intercept.y - \
			glpos->player.y) / tan(angle);
	glpos->step.y = 16;
	if (all->ray->updirect)
		glpos->step.y *= -1;
	glpos->step.x = glpos->step.y / tan(angle);
	if (all->ray->leftdirect && glpos->step.x > 0)
		glpos->step.x *= -1;
	if (all->ray->rightdirect && glpos->step.x < 0)
		glpos->step.x *= -1;
	calculhoridis(all, glpos, len);
}

void	calculvertidis(t_cub *all, t_glpos *glpos, int len)
{
	while ((((int)(glpos->intercept.y / 16) >= 0)
		&& (int)(glpos->intercept.y / 16) < len)
		&& ((int)(glpos->intercept.x / 16) >= 0)
		&& ((int)(glpos->intercept.x / 16) < \
		(int)ft_strlen(all->map[(int)glpos->intercept.y / 16]) * 16))
	{
		glpos->nbr = glpos->intercept.x;
		if (all->ray->leftdirect)
			glpos->nbr--;
		if (checkwall_ray(all, glpos->nbr, glpos->intercept.y))
		{
			glpos->verti_f = false;
			glpos->intercept.x += glpos->step.x;
			glpos->intercept.y += glpos->step.y;
		}
		else
		{
			glpos->verti_f = true;
			glpos->verti.x = glpos->intercept.x;
			glpos->verti.y = glpos->intercept.y;
			break ;
		}
	}
}

void	intercepverti(t_cub *all, t_glpos *glpos, double angle, int len)
{
	glpos->intercept.x = floor(glpos->player.x / 16) * 16;
	if (all->ray->rightdirect)
		glpos->intercept.x += 16;
	glpos->intercept.y = glpos->player.y + (glpos->intercept.x - \
			glpos->player.x) * tan(angle);
	glpos->step.x = 16;
	if (all->ray->leftdirect)
		glpos->step.x *= -1;
	glpos->step.y = glpos->step.x * tan(angle);
	if (all->ray->updirect && glpos->step.y > 0)
		glpos->step.y *= -1;
	if (all->ray->downdirect && glpos->step.y < 0)
		glpos->step.y *= -1;
	calculvertidis(all, glpos, len);
}

void	chosedistance(t_cub *all, t_glpos *glpos)
{
	if (glpos->verti_f)
		glpos->verti_d = calculdistance(glpos->player.x, \
				glpos->player.y, glpos->verti.x, glpos->verti.y);
	else
		glpos->verti_d = 1e30;
	if (glpos->hori_f)
		glpos->hori_d = calculdistance(glpos->player.x, \
				glpos->player.y, glpos->hori.x, glpos->hori.y);
	else
		glpos->hori_d = 1e30;
	if (glpos->hori_d < glpos->verti_d)
		chosedistance2(all, glpos);
	else
	{
		glpos->po.x = glpos->verti.x;
		glpos->po.y = glpos->verti.y;
		all->ray->distance = glpos->verti_d;
		all->hitv = true;
		glpos->hori_f = false;
		all->raydist[all->hitindex] = glpos->verti_d;
	}
	all->hitindex++;
}

void	hintercept(t_cub *all, double angle, t_glpos *glpos)
{
	int		len;
	double	departx;
	double	departy;
	double	finx;
	double	finy;

	initialiserinter(glpos);
	len = ft_strleny(all->map);
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	all->ray->downdirect = (angle >= 0 && angle <= M_PI);
	all->ray->updirect = !all->ray->downdirect;
	all->ray->rightdirect = ((angle < (0.5 * M_PI)) || \
			(angle > (1.5 * M_PI)));
	all->ray->leftdirect = !all->ray->rightdirect;
	intercephori(all, glpos, angle, len);
	intercepverti(all, glpos, angle, len);
	chosedistance(all, glpos);
	all->pos = glpos;
	departx = glpos->player.x - all->distancexx;
	departy = glpos->player.y - all->distanceyy;
	finx = glpos->po.x - all->distancexx;
	finy = glpos->po.y - all->distanceyy;
	lstaddback(&(all->node), lstnew(departx, departy, finx, finy));
}
